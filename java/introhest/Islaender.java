//Islandsk java er en d�rlig kaffe, p� linje med svensk kogekaffe ...
class Islaender extends Hest{
	int bonustype=0;

	void changeBonusType(int newType){
		bonustype=newType;
	}
	void printStatus(){
		System.out.println("Hest! Hest Isl�nder har to bonustyper.");
	}
}

