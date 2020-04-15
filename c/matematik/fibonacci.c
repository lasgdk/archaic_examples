/*
 *Calculate the n'th fibonacci number in two different ways
 *Copyright Lars Sommer, lasg@lasg, 2007
 */
#include <stdio.h>

int fibrec(int);
int fibite(int);

int main(int argc,char **argv){
	int n;

	if( argc>2 )
		n=atoi(argv[2]);
	if( argc != 3 || ( *argv[1]!='r' && *argv[1]!='i' ) || n==0)
	{
		printf("Usage: fibonacci i|r n\n");
		printf("Calculates the n'th Fibonacci number with either\n");
		printf(" an iterative (i) or a recursive (r) algorithm.\n");
		exit(1);
	}

	printf("n er %d\n\n",n);
	if( *argv[1]=='r' )
		printf("%d\n",fibrec(n));
	else
		fibite(n);
	return 0;
}

int fibrec(int n){
	int res;
	if( n==1 || n==2 )
		res=1;
	else
		res=fibrec(n-1) + fibrec(n-2);
	return res;
}

int fibite(int n){
	int r0=0,r1=1,r2=1,i;

	for(i=2;i<=n;i++)
	{
		r2=r0+r1;
		r0=r1;
		r1=r2;
	}

	printf("%d\n",r2);
	return 0;
}

