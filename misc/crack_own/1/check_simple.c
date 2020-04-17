main(){
	int a;
	a=42;
	if( a < 50 )
	{
		ok();
	}


	notok();
}

ok(){
	return 12;
}

notok(){
	return 13;
}

