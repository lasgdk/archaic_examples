#include <stdio.h>

int i[10], x;
float f[10];
double d[10];

main()
{
	printf("\t\tInteger\t\tFloat\t\tDouble");
	printf("\n================================");
	printf("======================");

	for (x=0; x<10; x++)
		printf("\nElement %d:\t%ld\t%ld\t%ld",x,&i[x],&f[x],&d[x]);
	printf("\n================================");
	printf("======================\n");

	return 0;
}

