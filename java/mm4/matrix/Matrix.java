
/**
 * Matrix.java is a fairly simple class designed to illustrate the
 * basic class structure in Java.  
 *
 * Created September 24 by Dimon.
 *
 * Updated to include Exceptions on October 29.
 *
 * Updated to implement Serializable on November 5.
 */

package matrix;

public class Matrix implements java.io.Serializable {       
    // Instance variables
    private int numRows;
    private int numCols;
    private double[][] elements;
    private boolean empty = true;
           
    
    /**
     * Default constructor, which creates an empty 2-by-2 matrix.
     */
    public Matrix() {
	this(2,2);
    }

    /**
     * Constructor that creates an empty n-by-m matrix.
     */
    public Matrix(int n, int m) {
	numRows = n;
	numCols = m;
	elements = new double[numRows][numCols];
    }

    /**
     * Constructor that creates an n-by-m matrix with specific
     * elements collected in the array entries.  
     */
    public Matrix(double[] entries, int n, int m) throws MatrixDimException {
	this(n, m);                 // Creates an empty n-by-m matrix 
	insertData(entries);        // Inserts the elements
    }

           
    /**
     * This method inserts the values contained in the array entries
     * in the matrix.  It uses the overloaded method insertData(double
     * entry, int i, int j) to insert the actual values.  
     */
    public void insertData(double[] entries) throws MatrixDimException {
	// Check that the number of values is OK
	if (numRows*numCols != entries.length) {
	    throw new MatrixDimException("Wrong number of entries!");
	} else {
	    int index = 0;
	    for (int i = 0; i < numRows; i++) {       // Individual rows
		for (int j = 0; j < numCols; j++) {   // Individual columns 
		    insertData(entries[index], i, j); // Insert value 
		    index++;                          // Increment index
		}
	    }
	}
    }

    /**
     * Inserts an individual value at position i,j.
     */
    public void insertData(double entry, int i, int j) {
	elements[i][j] = entry;
	if (empty) {
	    empty = false;
	}
    }

    /**
     * Returns a boolean indicating whether the matrix is empty. 
     */
    public boolean isEmpty() {
	return empty;
    }

    /**
     * Returns the number of rows. 
     */
    public int getNumRows() {
	return numRows;
    }

    /**
     * Returns the number of columns.
     */
    public int getNumCols() {
	return numCols;
    }

    /**
     * Returns an individual value at position i,j.
     */
    public double getData(int i, int j) throws EmptyMatrixException {
	if (empty) {
	    throw new EmptyMatrixException();
	} else {
	    return elements[i][j];
	}
    }

    /**
     * Returns row number i.
     */
    public double[] getRow(int i) throws EmptyMatrixException {
	double[] a = new double[numCols]; 
	for (int j = 0; j < numCols; j++) {
	    a[j] = getData(i,j);
	}
	return a;
    }

    /**
     * Returns column number j.
     */
    public double[] getColumn(int j) throws EmptyMatrixException {
	double[] a = new double[numRows]; 
	for (int i = 0; i < numRows; i++) {
	    a[i] = getData(i,j);
	}
	return a;
    }


    /**
     * Prints out the matrix to System.out.  
     */
    public void printMatrix() {
	String row = new String();
	if (empty) {
	    System.out.println("This matrix is empty.");
	} else {
	    for (int i = 0; i < numRows; i++) {     // Individual rows
		for (int j = 0; j < numCols; j++) { // Individual columns 
		    row = row + " " + elements[i][j];// Append value  
		}
		System.out.println(row);            // Print the row string
		row = "";                           // Empty the row string
	    }
	}
	System.out.println();
    }

    /**
     * Returns the transpose of the matrix.
     */
    public Matrix transpose() throws EmptyMatrixException {
	Matrix m = new Matrix(numCols,numRows);
	for (int i = 0; i < numRows; i++) {     // Individual rows
	    for (int j = 0; j < numCols; j++) { // Individual columns 
		m.insertData(getData(i,j),j,i); // Insert value in m  
	    }
	}
	return m;
    }


    /**
     * Returns the result of the matrix A multiplied by this matrix
     * from the left, i.e., This*A.  
     */
    public Matrix multiply(Matrix A) throws EmptyMatrixException, 
                                            MatrixDimException {
	if (A.getNumRows() != this.numCols) {
	    throw new MatrixDimException("The dimensions do not match!");
	} else {
	    Matrix m = new Matrix(numRows,A.getNumCols());// Result matrix 
	    double[] a = new double[A.getNumCols()];      // Column of A
	    double[] t = new double[numRows];             // Row of this matrix
	    for (int i = 0; i < numRows; i++) {           // Individual rows
		t = getRow(i);
		for (int j = 0; j < A.getNumCols(); j++) {// Individual cols 
		    a = A.getColumn(j);
		    m.insertData(vectorProduct(t,a),i,j); // Insert t*a in m  
		}
	    }
	    return m;
	}
    }
    
    /**
     * Returns the `dot product' between two arrays of doubles (i.e.,
     * vectors) of the same length.
     */
    private double vectorProduct(double[] a, double[] b) {
	double sum = 0;
	for (int i = 0; i < a.length; i++) {
	    sum = sum + a[i]*b[i];
	}
	return sum;
    }


    public static void main(String[] args) {
	Matrix A = new Matrix();     // A default empty matrix 
	double[] values = new double[] {3, 2, 1, 5, -9.0, -7};
	Matrix B = new Matrix(values,3,2);  // A 3-by-2 empty matrix
	
	A.insertData(5.0, 0,0);
	A.insertData(0.0, 0,1);
	A.insertData(0.0, 1,0);
	A.insertData(5.0, 1,1);
	A.printMatrix();
	B.insertData(values);
	B.printMatrix();

	try {
	    Matrix BT = B.transpose();
	    BT.printMatrix();
	    Matrix BBT = B.multiply(BT);
	    BBT.printMatrix();
	    A.multiply(BT).printMatrix(); // Non-instantiated matrix
	} catch (EmptyMatrixException ee) {
	    System.err.println("One of the matrices is empty!");
	} catch (MatrixDimException me) {
	    System.err.println(me.getMessage());
	}
    }
} // End of class Matrix
