/**
 * TinyClock.java
 *
 * A demo showing a very simple digital clock in a display
 *
 * 29-sep-06 by Dimon
 **/
 
 package threads;
 
 import javax.swing.*;
 import javax.swing.event.*; 
 import java.awt.*;
 import java.awt.event.*;
 import java.util.*;
 
 import matrix.LinearSystem;
 
 
 public class TinyClock extends Thread {
 	
 	private JFrame frame;
 	private JLabel display;
 	
 	private ArrayList<LinearSystem> tickers;
 	private ArrayList<Thread> tockers;
 	
 	/**
 	 * Default constructor - creates a not-so-tiny clock
 	 **/
 	public TinyClock() {
 		this(18);
 	}
 	
 	/** 
 	 * Constructor that creates a clock with adjustable display size
 	 */  
 	public TinyClock(int size) {
 		// Check font size
 		if((size < 3) || (size > 48)) {
 			System.err.println("Get real, man!");
 			System.exit(-1);
 		}
 		frame = new JFrame("A Nifty Little Clock");
 		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 		
 		display = new JLabel("   TinyClock!   ");
 		display.setFont(new Font("Helvetica",Font.PLAIN, size)); 		
 		frame.getContentPane().add(display, 	
 												 BorderLayout.CENTER);
 		
 		// Display the window.
 		frame.pack();
        frame.setVisible(true);
        
        // Create the listener lists
        tickers = new ArrayList<LinearSystem>();
        tockers = new ArrayList<Thread>();
        
        // Start the thread
        start();
 	}

	public void run() {
		Calendar cal;
		int count = 0;
		try {
			while(count < 5) {
				// Sleep for one second
				Thread.sleep(1000);
				count++;
				
				// Tick
				for(LinearSystem ticker : tickers) {
					ticker.timestep();
				}
				
				// Get the current time and update the display
				cal = Calendar.getInstance();
				String now = " " + cal.get(Calendar.HOUR_OF_DAY);
				now += " : " + cal.get(Calendar.MINUTE);
				now += " : " + cal.get(Calendar.SECOND) + " ";
				display.setText(now);
				
				// Tock and reset count
				if (count == 5) {
					System.out.println("Tock!");
					for(Thread tocker : tockers) {
						tocker.interrupt();
					}
					count = 0;
				}
			}
			
		} catch (InterruptedException ie) {
			// Zzzz..* What!?
		}
		
	}
 		
 
	public void addTicker(LinearSystem sys) {
		tickers.add(sys);
	}

	public void addTocker(Thread runner) {
		runner.start();
		tockers.add(runner);
	}
 		
	/**
	 * The main method simply creates a TinyClock and starts it
	 **/
    public static void main(String[] args) {
    	TinyClock tiny = new TinyClock(32);
    }
}
