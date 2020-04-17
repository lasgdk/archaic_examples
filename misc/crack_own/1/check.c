main(int argc, char **argv){
	int ret;
	int check;
	int a=0;
	if(argv[1])
		a=atoi(argv[1]);

	if(a)
		check = controlcode(a);


	if( check == 1 )
		ret = ok();
	else
		ret = notok();

	return ret;

}

ok(){
	return 42;
}
notok(){
	return 13;
}

controlcode(int tal){
	int p1,p2;
	p1=tal/10;
	p2=tal%10;
	if( p1 + p2 == 10 )
		return 1;
	else
		return 0;

}



