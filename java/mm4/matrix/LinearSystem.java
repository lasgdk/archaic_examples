/**
 * LinearSystem.java simulates a very simple set of autonomous coupled linear
 * difference equations.
 *
 * 30-Sep-06 by Dimon
 **/

package matrix;


public class LinearSystem {
	private Matrix A;
	private Matrix X;
	private Matrix newX;
	private MatrixFrame gui;
	
	/**
	 * Default constructor.
	 **/
	public LinearSystem() {
		A = null;
		X = null;
		gui = null;
	}
	

	/**
	 * Sets the initial value of the state vector. Note that the number of rows
	 * in the state vector must match the number of rows in the coefficient
	 * matrix, which must have been set in advance.
	 **/
	public void setInitX(Matrix initX) {
		if (A == null) {
			System.err.println("A has not been set yet!");
			return;
		}
		if (A.getNumRows() != initX.getNumRows()) {
			System.err.println("Wrong number of rows in X!");
			return;
		} else {
			X = initX;
		}
	} 

	/**
	 * Sets the system coefficient matrix.
	 **/
	public void setA(Matrix newA) {
		A = newA;
	} 

	/**
	 * Sets a MatrixFrame window in which the state vector can be displayed
	 **/
	public void setGUI(MatrixFrame frame) {
		gui = frame;
	} 
	
	/**
	 * Returns the current value of the state vector.
	 **/
	public Matrix getX() {
		return X;
	} 

	/**
	 * Returns the system coefficient matrix.
	 **/
	public Matrix getA() {
		return A;
	} 

	
	/**
	 * Computes the new state vector after one time step
	 **/
	public Matrix timestep() {
		newX = A.multiply(X);
		X = newX;
		if (gui != null) {
			gui.displayMatrix(X);
		}
		return X;
	}
	
	// Main for testing purposes
	public static void main(String[] args) {
		Matrix A = new Matrix(3,3);
		Matrix X0 = new Matrix(3,1);
		double[] valuesA = new double[] {0, 1, 0, 0, 0, 1, 5, -9.0, 0.3};
		double[] valuesX = new double[] {0, 1, 0};
		try {
			A.insertData(valuesA);
			X0.insertData(valuesX);
		} catch (MatrixDimException e) {
			// Can't go wrong
		}
		LinearSystem ls = new LinearSystem();
		ls.setA(A);
		ls.setInitX(X0);
		ls.setGUI(new MatrixFrame(X0));
		for(int i = 0;i < 10; i++) {
			ls.timestep();
		}
	}
}
