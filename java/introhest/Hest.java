class Hest{
	int speed=0,type=0;

	void changeSpeed(int speedAdd){
		speed = speed + speedAdd;
	}

	void changeType(int newType){
		type = newType;
	}
	void printStatus(){
		System.out.println("Hest! Hesten bev�ger sig i "+type+" med "+speed+" km i timen");
	}
}

