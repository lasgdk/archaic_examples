/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

   */

#include <stdio.h>

main()
{

int i,j,r=5;
int forrige[r];

for(i=0;i<=r;i++)
{
	forrige[i]=0;
}

forrige[r/2+1]=1;

for(i=0;i<=r;i++)
{
	//for(j=1;j<=i;j++)
		//printf("%d ",forrige[j]=forrige[j]+forrige[j-1]);
		printf("%d ",forrige[(r/2+1)-i]=forrige[(r/2+1)-i]+forrige[(r/2+1)-i-1]);
	printf("\n");
}

}
