/**
 * ClockSystem.java
 *
 * Demonstrates the use of Runnable and Thread
 *
 * 29-sep-06 by Dimon
 **/

import threads.*;
import matrix.*;

public class ClockSystem {

	public static void main(String[] args) {
		// Create Runnable objects
		TinyClock tiny = new TinyClock();
		TockSlave slave = new TockSlave();
		
		// Create linear system
		Matrix A = new Matrix(3,3);
		Matrix X0 = new Matrix(3,1);
		double[] valuesA = new double[] {0, 1, 0, 0, 0, 1, .5, -.9, 0.3};
		double[] valuesX = new double[] {0, 1, 0};
		try {
			A.insertData(valuesA);
			X0.insertData(valuesX);
		} catch (MatrixDimException e) {
			// Can't go wrong
		}
		LinearSystem sys = new LinearSystem();
		sys.setA(A);
		sys.setInitX(X0);
		sys.setGUI(new MatrixFrame(X0));
	
		
		// Ensure that they know about each other
		slave.addClock(tiny);
		tiny.addTocker(slave);
		tiny.addTicker(sys);
		
	}
} 
