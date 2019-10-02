/* Copyright (c) 2005 Russ Cox, MIT; see COPYRIGHT */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <task.h>

int goalArray[] = {1, 2, 3, 4, 5};
int testArray[] = {0, 0, 0, 0, 0};
int buffer;
int buffer2;
Tasklist taskList;

Channel *testChannel;
   Channel *channel2;
void task1SetArray(void *arg)
{
    printf("TASK1SET: TASK ID:%d\n",taskid());
    //printf("%d\n", 1);
    taskswitch();
    printf("VALUE: %d\n",1);
    taskswitch();
    printf("VALUE: %d\n",4);
    chansendul(arg,0);
}
void task2SetArray(void *arg)
{
    //printf("%d\n", 2);
    printf("TASK2SET: TASK ID:%d\n",taskid());
    taskswitch();
    printf("VALUE: %d\n",2);
    chansendul(arg,0);
}
void task3SetArray(void *arg)
{
    //printf("%d\n", 3);
    printf("TASK3SET: TASK ID:%d\n",taskid());
    taskswitch();
    printf("VALUE: %d\n",3);
    chansendul(arg,0);

}
void task4SetArray(void *arg)
{
}
void task5SetArray(void *arg)
{
}

void testtask(void *arg)
{
 
    channel2 = chancreate(sizeof(unsigned long), buffer2);
	//Task *task1, *task2, *task3, *task4, *task5;
    printf("TESTTASK: TASK ID:%d\n",taskid());

    taskcreate(task1SetArray, channel2, 32768);
    taskcreate(task2SetArray, channel2, 32768);
    taskcreate(task3SetArray, channel2, 32768);
    

    chanrecvul(channel2);
    chanrecvul(channel2);
    chanrecvul(channel2);
    chansendul(testChannel, 0);  
}

void taskmain(int argc, char **argv)
{
    printf("MAIN:     TASK ID:%d\n",taskid());

    //printf("Starting tests\n");

    testChannel = chancreate(sizeof(unsigned long), buffer);
    taskcreate(testtask, testChannel, 32768);
    chanrecvul(testChannel);
    taskexitall(0);
}

void *
emalloc(unsigned long n)
{
    return calloc(n, 1);
}
