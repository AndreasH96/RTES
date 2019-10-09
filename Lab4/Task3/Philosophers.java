
// Task 1 version of Philosophers without sync
import java.io.*;
import java.util.*;

public class Philosophers {
    private static int NUM_PHIL;
    private static Object[] forks;

    public static void main(String[] args) {
        Scanner num_phil = new Scanner(System.in);
        System.out.println("Enter amount of Philosophers: ");
        int number = Integer.parseInt(num_phil.nextLine());
        NUM_PHIL = number;
        num_phil.close();
        forks = new Object[NUM_PHIL];
        Philosopher[] phils = new Philosopher[NUM_PHIL];
        // Create forks
        for (int i = 0; i < NUM_PHIL; i++)
            forks[i] = new Object();

        for (int i = 0; i < NUM_PHIL; i++){
            if(i == 0){
                phils[i] = new Philosopher(i, forks[i-1],forks[i]);
            }
            else{
                phils[i] = new Philosopher(i, forks[i], forks[(i + 1) % NUM_PHIL]);
            }
        }    
        // Start all Philosopher threads
        for (int i = 0; i < NUM_PHIL; i++)
            phils[i].start();

        try {

            Thread.sleep(60000); // Idle here
        } catch (InterruptedException e) {
            System.out.println("main thread interrupted");
        }

        for (int i = 0; i < NUM_PHIL; i++)
            phils[i].requestTerminate();
        // Request termination
        // Wait for all to finish
        try {

            Thread.sleep(50); // Idle here
        } catch (InterruptedException e) {
            System.out.println("main thread interrupted");
        }
        // Print stats
        System.out.println("\nPhilosopher id:  Eaten   Thought     Waited");
        for (int i = 0; i < NUM_PHIL; i++) {
            int[] counterArray = phils[i].getEatThinkWaitCounterArray();
            System.out.println(i + "                " + counterArray[0] + "         " + counterArray[1] + "           "
                    + counterArray[2]);
        }
  
    }


    static class Fork {
        private int id;
        private boolean available;

        Fork(int id){
            this.id = id;
            this.available = true;
        }

        public void lock(){
            this.available = false;
        }
        public void release(){
            this.available = true;
        }
    }

    static class Philosopher extends Thread {
        private final Object leftFork, rightFork;
        private final int id;
        private int eatCounter;
        private int thinkCounter;
        private int waitCounter;
        private boolean notTerminated = false;

        public Philosopher(int id, Object leftFork, Object rightFork) {
            // Constructor
            this.id = id;
            this.leftFork = leftFork;
            this.rightFork = rightFork;
            this.notTerminated = true;
            this.eatCounter = 0;
            this.thinkCounter = 0;
            this.waitCounter = 0;
        }

        public void requestTerminate() {
            this.notTerminated = false;
        }

        private void eat() {
            System.out.println("Philosopher " + id + " is eating.");
            this.eatCounter++;
            try {
                Thread.sleep(1);forks[i+1]
            } catch (Exception e) {
                System.out.p,this.rightForkrintln("eat thread interrupted");
            }

        }

        private void think() {
            System.out.println("Philosopher " + id + " is thinking.");
            this.thinkCounter++;
            try {
                Thread.sleep(1);
            } catch (Exception e) {
                System.out.println("think thread interrupted");
            }
        }

        private void waiting() {
            System.out.println("Philosopher " + id + " is waiting.");
            this.waitCounter++;
            try {
                Thread.sleep(1);
            } catch (Exception e) {
                System.out.println("waiting thread interrupted");
            }
        }

        public int[] getEatThinkWaitCounterArray() {
            int[] counterArray = { this.eatCounter, this.thinkCounter, this.waitCounter };
            return (counterArray);
        }

        public void run() {
            while (this.notTerminated) {
                think();
                waiting();
                
                    synchronized (this.leftFork) {
                        System.out.println("Philosopher " + id + " picked up left fork");
                        synchronized (this.rightFork) {
                            System.out.println("Philosopher " + id + " picked up right fork");
                            eat();
                        }
                    }
                

            }
            System.out.println("Philosopher " + id + " is full and tired of thinking(read terminated)");
        }
    }
}