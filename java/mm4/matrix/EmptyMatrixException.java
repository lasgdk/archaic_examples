package matrix;

public class EmptyMatrixException extends RuntimeException {
    String exceptionString;
    
    public EmptyMatrixException() {
	this.exceptionString = "Empty matrix";
    }

    public String getMessage() {
	return exceptionString;
    }
}
