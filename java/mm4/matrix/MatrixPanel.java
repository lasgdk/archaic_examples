/**
 * MatrixPanel - overrides paint() to display a Matrix Object
 **/

package matrix;

class MatrixPanel extends javax.swing.JPanel {
	
	Matrix matrix;
	
	public void setMatrix(Matrix m) {
		matrix = m;
	}
		
	public void paint(java.awt.Graphics g) {
	    String s;
	    
	    g.clearRect(0,0,500,500);
	    g.setColor(java.awt.Color.black);
	    if (matrix != null) {
			int n = matrix.getNumRows();
			int m = matrix.getNumCols();
			try {
		    	for (int i = 0; i < n; i++) { // Individual rows
					for (int j = 0; j < m; j++) { // Individual cols 
			    		s = Double.toString(matrix.getData(i,j));
			    		g.drawString(s,  j*40+30, i*40+30); 
					}
		    	}
			} catch (EmptyMatrixException e) {
		    	g.drawString("The matrix is empty.", 5,30);
			}
	    }
	}
	
}
