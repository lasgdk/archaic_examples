
/*public class Adder implements Runnable{
	        public void run(){
			                tal++;
					        }
}

public class Subber implements Runnable{
	        public void run(){
			                tal--;
					        }
}
						*/

public class Threads{
	public static void main(String[] args){
		int tal=0;
		(new Thread(new Adder(tal))).start();
		 System.out.println(tal);
	}
}

