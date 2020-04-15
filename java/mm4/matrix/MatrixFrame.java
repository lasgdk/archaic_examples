/**
 * MatrixFrame displays a Matrix in a separate window.
 *
 * 30-sep-06 by Dimon
 **/

package matrix;


import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;


public class MatrixFrame extends JFrame {

	private MatrixPanel myPanel;
	
	/**
     * Default constructor.
     */
    public MatrixFrame() {
		super("Matrix Demo");
		createGUI();
	}
	
	/**
     * Constructor taking a Matrix object as an argument.
     */
    public MatrixFrame(Matrix M) {
		super("Matrix Demo");
		createGUI();
		displayMatrix(M);
	}
	
	/**
	 * Updates the display to show the argument Matrix
	 **/
	public void displayMatrix(Matrix M) {
		myPanel.setMatrix(M);
		myPanel.repaint();
	}
	
	
	private void createGUI() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		myPanel = new MatrixPanel();
		
		// Put the display objects in the content pane
		getContentPane().setLayout(new BorderLayout());
		getContentPane().add(myPanel,BorderLayout.CENTER);

		setSize(200,320);
		setVisible(true);

	}
	
	public static void main(String[] args) {
	    double[] values = new double[] {3, 2, 1, 5, -9.0, 0};
	    Matrix A = new Matrix(3, 2);
	    try {
			A.insertData(values);
		} catch (MatrixDimException e) {
			// Can't go wrong
		}
		MatrixFrame mf = new MatrixFrame(A);
		
	}

}
