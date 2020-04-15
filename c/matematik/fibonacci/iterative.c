/*
 *Beregner fibonaccitallene op til 47'ne tal, iterativt.
 Lars Sommer, lasg@lasg.dk, 2007-04-17
 * */
int main(void){
	int u=1;
	int f=1;
	int g=0;
	int i;

	for(i=3;i<49;i++)
	{
		g=f;
		f=f+u;
		u=g;
		printf("Fibonaccital nr %d er %d\n",i-1,g);
	}
	return 0;
}
