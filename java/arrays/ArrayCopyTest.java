//Playing with 
//public static void arraycopy(Object src,
//                             int srcPos,
//                             Object dest,
//                             int destPos,
//                             int length)

class ArrayCopyTest{
	public static void main(String[] argv){
		char[] KaffeArray = {'d','e','c','a','f','f','e','i','n','a','t','e','d'};
		char[] NytKaffeArray = new char[7];

		System.arraycopy(KaffeArray,2,NytKaffeArray,0,7);
		System.out.println(new String(NytKaffeArray));
	}
}

