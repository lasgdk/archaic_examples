/**
 * TockSlave.java
 *
 * Demonstrates the use of interrupt() and join()
 *
 * 29-sep-06 by Dimon
 **/

package threads;

public class TockSlave extends Thread {

	TinyClock clock;
	int numTocks = 0;
		
    public void run() {
        System.out.println("Hello from the TockSlave thread!");
  		while (true) {      
			try {
   	    		// Sleep for a looooong time
   	    		Thread.sleep(10000000);
   	    	} catch(InterruptedException ie) {
   	    		// Wake up, sleepyhead!
   	    		numTocks++;
   	    		System.out.println("Heard a Tock!");
   	    		if (numTocks == 3) {
   	    			try {
   	    				System.out.println("TockSlave attaches itself.");
		       			clock.join();
		       		} catch (InterruptedException e) {
		       			// Finished!
		       			System.out.println("TockSlave terminates.");
		       			return;
		       		}
   	    		}
   	    	} 
   	    	// Go back to sleep
       	}
    }
    
    public void addClock(TinyClock tc) {
    	clock = tc;
    }

}
