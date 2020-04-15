/**
 * DynamicSystem.java
 *
 * A very simple autonomous linear system driven by external 
 * interrupts.
 *
 * 29-sep-06 by Dimon
 **/

package threads;

import matrix.*;

public class DynamicSystem extends Thread {

	private Matrix A;
	private Matrix X;
	
	/**
	 * Default constructor
	 **/
	public DynamicSystem() {
		double[] a = new double
		A = new Matrix();
		X = new Matrix();
		
	}
	
	public void run() {
		while(true) {
			try {
				Thread.sleep(100000);
				
			} catch(InterruptedException ie) {
				Matrix newX = A.multiply(X);
		
				X = newX;
			}
		} // Go back to sleep
	}
	
}
