#include <stdio.h>
#define MAX 5

int x[MAX], y[MAX], z[MAX], cnt, sum(int x[],int y[]), udskriv(int x[], int y[], int z[]);

main()
{
	for (cnt=0; cnt<MAX; cnt++)
		scanf("%d",&x[cnt]);
	for (cnt=0; cnt<MAX; cnt++)
		scanf("%d",&y[cnt]);
	sum(x,y);
	udskriv(x,y,z);
	return 0;
}

int sum(int x[],int y[])
{
	for(cnt=0;cnt<MAX;cnt++)
		z[cnt] = x[cnt] + y[cnt];
	return *z;
}

int udskriv(int x[], int y[], int z[])
{
	printf("\nX\tY\tZ\n");
	for(cnt=0;cnt<MAX;cnt++)
		printf("%d\t%d\t%d\n",x[cnt],y[cnt],z[cnt]);
	return 0;
}

