char bytecode[]="\x68\xC0\x81\x00\x00\xE9\x11\x00\x00\x00\x5B\x53\xB0\x08\x50\xCD\x80\x68\x00\x00\x00\x00\xB0\x01\x50\xCD\x80\xE8\xEA\xFF\xFF\xFF\x74\x65\x73\x74\x00";
	
main()
{
	void (*run)()=(void*)bytecode;
	run();
}
