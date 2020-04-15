/*
 * Beregning af fibonaccital ved brug af et array. 
 * Med et integer-array er der kun plads til de første 46 tal.
 * 2007-04-17
 * */

int t[47];

int main(void){
	int i;
	t[0]=1;
	t[1]=1;
	for(i=2;i<100;i++)
		t[i]=0;
	tabf(46);
	return 0;
}

int tabf(int n){
	if( t[n]==0 ){
		t[n]=tabf(n-1) + tabf(n-2);
		printf("Fibonaccital nr %d er %d\n",n+1,t[n]);
	}
	return t[n];
}

