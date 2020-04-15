/*this is unused and useless../lars*/
main(){

	int a[10];
	int i,j;
	int res[3];
	for(i=0;i<10;i++)
	{
		a[i]=i;
	}
	for(i=0;i<=2;i++)
	{
		res[i]=0;

	}

	for(i=0;i<10;i++)
	{
			res[i%3]+=a[i];


	}

	printf("%d %d %d\n",res[0],res[1],res[2]);

	return 0;

}
