
/**
 * MatrixDemo1.java puts a GUI in front of the Matrix class, where it
 * is possible to enter values dynamically.  This obviously opens up
 * for many possibilities for errors, which will be handled through
 * exceptions.
 * 
 * Created October 16 by Dimon.  
 */
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import matrix.*;


public class MatrixDemo1 extends JFrame {
    Matrix A = null; 
    Matrix B = null;
    MatrixControls controls;
    MatrixPanel panel;
               
    /**
     * Constructor.
     */
    public MatrixDemo1() {
	super("Matrix Demo");
	addWindowListener(new WindowAdapter() {
		public void windowClosing(WindowEvent e) {
		    System.exit(0);
		}
	    });
	setSize(420,320);

	// Create the display objects
	panel = new MatrixPanel();
	controls = new MatrixControls(panel, this);

	// Put the display objects in the content pane
	getContentPane().setLayout(new BorderLayout());
	getContentPane().add(panel,BorderLayout.CENTER);
	getContentPane().add(controls,BorderLayout.SOUTH);
    }    

    public static void main(String[] args) {
	MatrixDemo1 demo = new MatrixDemo1();
	demo.setVisible(true);
    } // End of main


    class MatrixPanel extends JPanel {
	public String matrixName = null;
	public Matrix matrix = null;
               
	public void paint(Graphics g) {
	    String s;

	    g.clearRect(0,0,500,500);
	    g.setColor(java.awt.Color.black);
	    if (matrix != null) {
		g.drawString(matrixName, 5,15);
		int n = matrix.getNumRows();
		int m = matrix.getNumCols();
		try {
		    for (int i = 0; i < n; i++) { // Individual rows
			for (int j = 0; j < m; j++) { // Individual cols 
			    s = Double.toString(matrix.getData(i,j));
			    g.drawString(s, i*40, j*40+50); 
			}
		    }
		} catch (EmptyMatrixException e) {
		    g.drawString("The matrix is empty.", 5,30);
		}
	    }
	}
               
	public void redraw(Matrix M, String n) {
	    this.matrix = M;
	    this.matrixName = n;
	    repaint();
	}
               
    } // End of class MatrixPanel
           
    class MatrixControls extends JPanel implements ActionListener {
	MatrixPanel panel;
	MatrixDemo1 rootWindow;
	
	JButton bbt;
               
	/**
	 * Constructor.
	 */
	public MatrixControls(MatrixPanel panel, MatrixDemo1 rootWindow) {
	    this.panel = panel;     
	    this.rootWindow = rootWindow;

	    JButton a = new JButton("Enter A");
	    JButton b = new JButton("Enter B");
	    JButton atb = new JButton("AT*B");
	    JButton ab = new JButton("A*B");
	    bbt = new JButton("B*BT");
                           
	    a.addActionListener(this);
	    b.addActionListener(this);
	    atb.addActionListener(this);
	    ab.addActionListener(this);
	    bbt.addActionListener(this);

	    add(b);
	    add(a);
	    add(atb);
	    add(ab);
	    add(bbt);
	} 

	private Matrix enterMatrix(MatrixDemo1 rootWindow) {
	    String rows = JOptionPane.showInputDialog(rootWindow,
			  "Please enter the number of rows of the matrix.",
			  "Enter value",
			  JOptionPane.INFORMATION_MESSAGE);
	    String cols = JOptionPane.showInputDialog(rootWindow,
                          "Please enter the number of columns of the matrix.",
			  "Enter value",
                          JOptionPane.INFORMATION_MESSAGE);
	    int n = Integer.parseInt(rows);
	    int m = Integer.parseInt(cols);
	    // Return a zero m-by-n matrix
	    return new Matrix(new double[n*m], m, n);
	}
                   

	public void actionPerformed(ActionEvent ev) {
	    String label = ev.getActionCommand();
	    Matrix m = new Matrix();
	    try {
		if (label.equals("Enter A")) {
		    A = enterMatrix(this.rootWindow);
		    m = A;
		} else if (label.equals("Enter B")) {
		    B = enterMatrix(this.rootWindow);
		    m = B;
		} else if (label.equals("AT*B")) {
		    m = A.transpose().multiply(B);
		} else if (label.equals("A*B")) {
		    m = A.multiply(B);
		} else if (bbt==(JButton)ev.getSource()) {
		    m = B.multiply(B.transpose());
		}
		panel.redraw(m,label);
		
	    } catch (NullPointerException np) {
		JOptionPane.showMessageDialog(rootWindow,
                            "The matrix has not been initialized!",
					      "Matrix error",
					      JOptionPane.ERROR_MESSAGE);
	    } catch (EmptyMatrixException em) {
		JOptionPane.showMessageDialog(rootWindow,
					      "One of the matrices is empty!",
					      "Matrix error",
					      JOptionPane.ERROR_MESSAGE);
	    } catch (MatrixDimException em) {
		JOptionPane.showMessageDialog(rootWindow, 
					      em.getMessage(),
					      "Matrix error",
					      JOptionPane.ERROR_MESSAGE);
	    }
	}
    } // End of class MatrixControls     
} // End of class MatrixDemo1
