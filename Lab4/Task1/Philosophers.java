// Task 1 version of Philosphers without sync
import java.io.*; 
import java.util.*; 



public class Philosophers {
    private static int NUM_PHIL;
    private static Fork[] forks;

    
    public static void main(String[] args) {
        Scanner num_phil = new Scanner(System.in);
        System.out.println("Enter amount of Philosophers: ");
        int number = Integer.parseInt(num_phil.nextLine());
        NUM_PHIL = number;
        forks = new Fork[NUM_PHIL];
        Philosopher[] phils = new Philosopher[NUM_PHIL];
        // Create forks
        for (int i = 0; i < NUM_PHIL; i++)
            forks[i] = new Fork();
            
        for (int i = 0; i < NUM_PHIL; i++)
            phils[i] = new Philosopher(i, forks[i], forks[(i + 1) % NUM_PHIL]);
        // Start all Philosopher threads
        for (int i = 0; i < NUM_PHIL; i++)
            phils[i].start(); 
            
        
            
        
        
        try{
            Thread.sleep(2000); // Idle here
        }
            catch(InterruptedException e){
            System.out.println("main thread interrupted");
        }
        
        for (int i = 0; i < NUM_PHIL; i++)
            phils[i].requestTerminate();
        // Request termination
        // Wait for all to finish

        System.out.println("\nPhilosopher id:  Eaten   Thought     Waited");
        for(int i = 0; i < NUM_PHIL; i++){
        int[] counterArray = phils[i].getEatThinkWaitCounterArray();
        System.out.println(i + "                " + counterArray[0] + "         " + counterArray[1] + "           " + counterArray[2]);
        }
        // Print stats
    }
    static class Fork{
        private boolean available;
        Fork(){
            available = true;
        }
        synchronized public void lockResource(){
            available = false;
        }
        synchronized public void unlockResource(){
            available = true;
        }
        synchronized public boolean isAvailable(){
            return available;
        }
            
    }

    static class Philosopher extends Thread {
        private final Fork leftFork, rightFork;
        private final int id;
        private int eatCounter;
        private int thinkCounter;
        private int waitCounter;
        private boolean notTerminated = false;
        private boolean holdingLeft = false, holdingRight = false;

        public Philosopher(int id, Fork leftFork, Fork rightFork) {
            // Constructor
            this.id = id;
            this.leftFork = leftFork;
            this.rightFork = rightFork;
            this.notTerminated = true;
            this.eatCounter = 0;
            this.thinkCounter = 0;
            this .waitCounter = 0;
        }

        public void requestTerminate() {
            // CHECK SOMETHING?
            this.putDownLeftFork();
            this.putDownRightFork();
            this.notTerminated = false;
        }

        private void eat() {
            System.out.println("Philosopher " + id + " is eating.");
            this.eatCounter++;
            try {
                Thread.sleep(50);
            } catch (Exception e) {
                System.out.println("eat thread interrupted");
            }
            
        }

        private void think() {
            System.out.println("Philosopher " + id + " is thinking.");
            this.thinkCounter++;
            try {
                Thread.sleep(25);
            } catch (Exception e) {
                System.out.println("think thread interrupted");
            }
        }

        private void waiting() {
            System.out.println("Philosopher " + id + " is waiting.");
            this.waitCounter++;
            try {
                Thread.sleep(15);
            } catch (Exception e) {
                System.out.println("waiting thread interrupted");
            }
        }

        private void pickUpLeftFork() {
            // Syncrhonization here
            synchronized (this) {
                if (this.leftFork.isAvailable() && !this.holdingLeft) {
                    // locks the resource
                    this.leftFork.lockResource();
                    // picks up the fork
                    this.holdingLeft = true;
                }
            }
        }

        private void putDownLeftFork() {
            // Syncrhonization here
            synchronized (this) {
                if (this.holdingLeft) {
                    // puts down the fork
                    this.holdingLeft = false;
                    // unlock the resource
                    this.leftFork.unlockResource();
                }
            }
        }

        private void pickUpRightFork() {
            // Synchronization here
            synchronized (this) {
                if (this.rightFork.isAvailable() && !this.holdingRight) {
                    // locks the resource
                    this.rightFork.lockResource();
                    // picks up the fork
                    this.holdingRight = true;
                }
            }
        }

        private void putDownRightFork() {
            // Syncrhonization here
            synchronized (this) {
                if (this.holdingRight) {
                    // puts down the fork
                    this.holdingRight = false;
                    // unlock the resource
                    this.rightFork.unlockResource();
                }
            }
        }
        public int[] getEatThinkWaitCounterArray(){
            int[] counterArray = {this.eatCounter, this.thinkCounter, this.waitCounter};
            return (counterArray);
        }

        public void run() {
            while (this.notTerminated) {
                think();
                pickUpLeftFork();
                pickUpRightFork();

                if(this.holdingLeft && this.holdingRight){
                    eat();
                    putDownRightFork();
                    putDownLeftFork();
                }
                else{
                    waiting();
                }
                // put down forks
                try {
                    Thread.sleep(100);
                } catch (Exception e) {
                    System.out.println("run thread interrupted");
                }
            }
            System.out.println("Philosopher " + id + " is full and tired of thinking(read terminated)");
        }
    }
}