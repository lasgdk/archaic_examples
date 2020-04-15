package matrix;

public class MatrixDimException extends RuntimeException {
    String exceptionString;
    
    public MatrixDimException() {
	this("Wrong matrix dimensions");
    }

    public MatrixDimException(String str) {
	this.exceptionString = str;
    }

    public String getMessage() {
	return exceptionString;
    }
}
