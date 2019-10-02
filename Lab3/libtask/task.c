/* Copyright (c) 2005 Russ Cox, MIT; see COPYRIGHT */

#include "taskimpl.h"
#include <fcntl.h>
#include <stdio.h>
int taskdebuglevel;
int taskcount;
int tasknswitch;
int taskexitval;
Task *taskrunning;

Context taskschedcontext;
Tasklist taskrunqueue;
// Double pointer to the list of tasks
Task **alltask;
// Position of the last added task
int nalltask;

static char *argv0;
static void contextswitch(Context *from, Context *to);

static void
taskdebug(char *fmt, ...)
{
	// List of arguments given in ...
	va_list arg;
	char buf[128];
	Task *t;
	char *p;
	static int fd = -1;

	return;
	va_start(arg, fmt);
	vfprint(1, fmt, arg);
	va_end(arg);
	return;

	if (fd < 0)
	{
		p = strrchr(argv0, '/');
		if (p)
			p++;
		else
			p = argv0;
		snprint(buf, sizeof buf, "/tmp/%s.tlog", p);
		if ((fd = open(buf, O_CREAT | O_WRONLY, 0666)) < 0)
			fd = open("/dev/null", O_WRONLY);
	}

	va_start(arg, fmt);
	vsnprint(buf, sizeof buf, fmt, arg);
	va_end(arg);
	t = taskrunning;
	if (t)
		fprint(fd, "%d.%d: %s\n", getpid(), t->id, buf);
	else
		fprint(fd, "%d._: %s\n", getpid(), buf);
}

static void
taskstart(uint y, uint x)
{
	Task *t;
	ulong z;

	z = x << 16; /* hide undefined 32-bit shift from 32-bit compilers */
	z <<= 16;
	z |= y;
	t = (Task *)z;

	//print("taskstart %p\n", t);
	t->startfn(t->startarg);
	//print("taskexits %p\n", t);
	taskexit(0);
	//print("not reacehd\n");
}

static int taskidgen;

static Task *
taskalloc(void (*fn)(void *), void *arg, uint stack)
{
	Task *t;
	sigset_t zero;
	uint x, y;
	ulong z;

	/* Allocate the task and stack together */
	t = malloc(sizeof *t + stack);
	// If no memory could be allocated for the task
	if (t == nil)
	{
		fprint(2, "taskalloc malloc: %r\n");
		abort();
	}
	// Fills the task memory with zeros
	memset(t, 0, sizeof *t);
	// Sets the position of the task stack
	t->stk = (uchar *)(t + 1);
	// Registers the stack size for the task
	t->stksize = stack;
	// Sets the task ID
	t->id = ++taskidgen;
	// Sets the starting function of the task
	t->startfn = fn;
	// Sets the input arguments for the function of the task
	t->startarg = arg;

	/* do a reasonable initialization */
	memset(&t->context.uc, 0, sizeof t->context.uc);
	// Sets the adress of the set of signals to be blocked, unblocked or waited
	sigemptyset(&zero);
	// Used to fetch and/or change the signal mask of the calling thread
	// SIG_BLOCK says to change the blocking of signals
	sigprocmask(SIG_BLOCK, &zero, &t->context.uc.uc_sigmask);

	/* must initialize with current context */
	if (getcontext(&t->context.uc) < 0)
	{
		fprint(2, "getcontext: %r\n");
		abort();
	}

	/* call makecontext to do the real work. */
	/* leave a few words open on both ends */
	t->context.uc.uc_stack.ss_sp = t->stk + 8;
	t->context.uc.uc_stack.ss_size = t->stksize - 64;
#if defined(__sun__) && !defined(__MAKECONTEXT_V2_SOURCE) /* sigh */
#warning "doing sun thing"
	/* can avoid this with __MAKECONTEXT_V2_SOURCE but only on SunOS 5.9 */
	t->context.uc.uc_stack.ss_sp =
		(char *)t->context.uc.uc_stack.ss_sp + t->context.uc.uc_stack.ss_size;
#endif
	/*
	 * All this magic is because you have to pass makecontext a
	 * function that takes some number of word-sized variables,
	 * and on 64-bit machines pointers are bigger than words.
	 */
	//print("make %p\n", t);
	z = (ulong)t;
	y = z;
	z >>= 16; /* hide undefined 32-bit shift from 32-bit compilers */
	x = z >> 16;
	makecontext(&t->context.uc, (void (*)())taskstart, 2, y, x);

	return t;
}

int taskcreate(void (*fn)(void *), void *arg, uint stack)
{
	int id;
	Task *t;
	// Allocates memory for the new task
	t = taskalloc(fn, arg, stack);
	// Increments the count for amount of tasks
	taskcount++;
	// Assigns a task-ID to the new task
	id = t->id;
	// If the memory of alltasks has to be incremented
	if (nalltask % 64 == 0)
	{
		// Increment the size of **alltask by 64 positions by reallocating its memory
		alltask = realloc(alltask, (nalltask + 64) * sizeof(alltask[0]));
		// If no memory could be allocated to alltask, out of memory
		if (alltask == nil)
		{
			fprint(2, "out of memory\n");
			abort();
		}
	}
	// Assigns the task which position it has in alltask
	t->alltaskslot = nalltask;
	// Adds the task to alltask
	alltask[nalltask++] = t;
	// Sets the state of task t to ready
	taskready(t);
	// Returns the assigned ID of the task
	return id;
}

void tasksystem(void)
{
	if (!taskrunning->system)
	{
		// Makes the current task a "system" task
		taskrunning->system = 1;
		--taskcount;
	}
}

/*-----------------------------------------*/

void taskswitch(void)
{
	contextswitch(&taskrunning->context, &taskschedcontext);
	needstack(0);
}
/*-----------------------------------------*/

void taskready(Task *t)
{
	// Sets the task ready flag
	t->ready = 1;
	// Adds the task to the queue
	addtask(&taskrunqueue, t);
}

int taskyield(void)
{
	int n;

	n = tasknswitch;
	// Task gives up the CPU, lets all other ready tasks run before it runs again
	// The return value is the amount of tasks that ran while the current task was waiting
	return tasknswitch - n - 1;
}

int anyready(void)
{
	// Returns true if there are any tasks in the ready queue
	return taskrunqueue.head != nil;
}

void taskexitall(int val)
{
	// Exits all tasks and the entire program given the exit status val
	exit(val);
}

void taskexit(int val)
{
	// Exits the current tasks, if there are no other non-system tasks shut down the program
	taskexitval = val;
	taskrunning->exiting = 1;
	taskswitch();
}

static void
contextswitch(Context *from, Context *to)
{
	// Swaps the context using swapcontext
	if (swapcontext(&from->uc, &to->uc) < 0)
	{
		fprint(2, "swapcontext failed: %r\n");
		assert(0);
	}
}

static void
taskscheduler(void)
{
	int i;
	Task *t;

	taskdebug("scheduler enter");
	// Will be compiled into a while(1)
	for (;;)
	{
		// If no tasks left, exit the program
		if (taskcount == 0)
			exit(taskexitval);
		// Gets the head of the task queue
		t = taskrunqueue.head;
		// If the queue head is nil, no tasks are ready, exit the program
		if (t == nil)
		{
			fprint(2, "no runnable tasks! %d tasks stalled\n", taskcount);
			exit(1);
		}
		// Remove the task from the queue
		deltask(&taskrunqueue, t);
		t->ready = 0;
		// Updates the running tasks
		taskrunning = t;
		// Increment the amount of times tasks has been switched
		tasknswitch++;
		// Run the task debug
		taskdebug("run %d (%s)", t->id, t->name);
		// Run the task
		contextswitch(&taskschedcontext, &t->context);
		//print("back in scheduler\n");
		taskrunning = nil;
		// If the task is set to exit
		if (t->exiting)
		{
			if (!t->system)
				taskcount--;
			i = t->alltaskslot;
			alltask[i] = alltask[--nalltask];
			alltask[i]->alltaskslot = i;
			free(t);
		}
	}
}

void **
taskdata(void)
{
	return &taskrunning->udata;
}

/*
 * debugging
 */
void taskname(char *fmt, ...)
{
	va_list arg;
	Task *t;

	t = taskrunning;
	va_start(arg, fmt);
	vsnprint(t->name, sizeof t->name, fmt, arg);
	va_end(arg);
}

char *
taskgetname(void)
{
	return taskrunning->name;
}

void taskstate(char *fmt, ...)
{
	va_list arg;
	Task *t;

	t = taskrunning;
	va_start(arg, fmt);
	vsnprint(t->state, sizeof t->name, fmt, arg);
	va_end(arg);
}

char *
taskgetstate(void)
{
	return taskrunning->state;
}

void needstack(int n)
{
	Task *t;

	t = taskrunning;

	if ((char *)&t <= (char *)t->stk || (char *)&t - (char *)t->stk < 256 + n)
	{
		fprint(2, "task stack overflow: &t=%p tstk=%p n=%d\n", &t, t->stk, 256 + n);
		abort();
	}
}

static void
taskinfo(int s)
{
	int i;
	Task *t;
	char *extra;

	fprint(2, "task list:\n");
	for (i = 0; i < nalltask; i++)
	{
		t = alltask[i];
		if (t == taskrunning)
			extra = " (running)";
		else if (t->ready)
			extra = " (ready)";
		else
			extra = "";
		fprint(2, "%6d%c %-20s %s%s\n",
			   t->id, t->system ? 's' : ' ',
			   t->name, t->state, extra);
	}
}

/*
 * startup
 */

static int taskargc;
static char **taskargv;
int mainstacksize;

static void
taskmainstart(void *v)
{
	taskname("taskmain");
	taskmain(taskargc, taskargv);
}

int main(int argc, char **argv)
{
	struct sigaction sa, osa;

	memset(&sa, 0, sizeof sa);
	sa.sa_handler = taskinfo;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, &osa);

#ifdef SIGINFO
	sigaction(SIGINFO, &sa, &osa);
#endif

	argv0 = argv[0];
	taskargc = argc;
	taskargv = argv;

	if (mainstacksize == 0)
		mainstacksize = 256 * 1024 * 1024;
	taskcreate(taskmainstart, nil, mainstacksize);
	taskscheduler();
	fprint(2, "taskscheduler returned in main!\n");
	abort();
	return 0;
}

/*
 * hooray for linked lists
 */
void addtask(Tasklist *l, Task *t)
{
	if (l->tail)
	{
		l->tail->next = t;
		t->prev = l->tail;
	}
	else
	{
		l->head = t;
		t->prev = nil;
	}
	l->tail = t;
	t->next = nil;
}

void deltask(Tasklist *l, Task *t)
{
	if (t->prev)
		t->prev->next = t->next;
	else
		l->head = t->next;
	if (t->next)
		t->next->prev = t->prev;
	else
		l->tail = t->prev;
}

unsigned int
taskid(void)
{
	return taskrunning->id;
}
