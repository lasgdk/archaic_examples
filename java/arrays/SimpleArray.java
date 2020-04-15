class SimpleArray{
	public static void main(String[] argv){
		int[] mitArray;
		mitArray = new int[5];

		mitArray[0]=1;
		mitArray[1]=2;
		mitArray[2]=3;
		mitArray[3]=123;
		//mitArray[4] defaults to 0

		System.out.println(mitArray[0] +" "+ mitArray[1] +" "+ mitArray[2] +" "+mitArray[3] +" "+mitArray[4] );
	}
}
