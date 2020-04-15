//Islandsk java er en dårlig kaffe, på linje med svensk kogekaffe ...
class Islaender extends Hest{
	int bonustype=0;

	void changeBonusType(int newType){
		bonustype=newType;
	}
	void printStatus(){
		System.out.println("Hest! Hest Islænder har to bonustyper.");
	}
}

