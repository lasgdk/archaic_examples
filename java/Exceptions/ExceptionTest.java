
import java.util.*;

public class ExceptionTest{
	public static void main(String[] arg){
		ArrayList arr = new ArrayList();
		try{
			arr.get(3);
		}
		catch (Exception err){
			System.out.println("Hov, der er en fejl..");
		}

		try{
			arr.get(3);
		}
		catch(Exception err){
			try{
				System.out.println("Og to fejl inde i hinanden..");
				arr.get(5);
			}
			catch(Exception err2){
				System.out.println("Lige her.");
			}
		}
		try{
			throw new EmptyStackException();
		}
		catch(EmptyStackException ese){
				System.out.println("hihi jeg greb din fejl!");
		}
	}
}


