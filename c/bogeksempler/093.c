#include <stdio.h>
#define MAX 10

int array[MAX], count;
int stoerste(int x[], int y);

main()
{
	for (count=0; count < MAX; count++)
	{
		printf("Indtast værdi nr.%d: ",count+1);
		scanf("%d",&array[count]);
	}

	printf("\nDen største værdi du indtastede, var %d\n", stoerste(array, MAX));
	return 0;
}

int stoerste(int x[], int y)
{
	int count, hoejest = -12000;
	for (count = 0; count <y; count++)
	{
		if(x[count] > hoejest)
			hoejest=x[count];
	}
	return hoejest;
}
