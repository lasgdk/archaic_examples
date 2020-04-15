public class TastaturInput{
	public static void main(String[] arg){
		//Forbered noget til at se på tasteinput
		java.util.Scanner mitTastatur = new java.util.Scanner(System.in);
		System.out.println("Nu kan du skrive et tal (en int):");
		int tal;
		tal = mitTastatur.nextInt();
		System.out.println("Du skrev " + tal);
	}
}

