class HesteDemo {
	public static void main(String[] argv){
		Hest hest1 = new Hest();
		Hest hest2 = new Hest();

		hest1.changeSpeed(10);
		hest1.printStatus();

		hest2.changeType(2);
		hest2.printStatus();

		Islaender hest3 = new Islaender();
		hest3.printStatus();
	}
}
