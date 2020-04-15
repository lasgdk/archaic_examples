/* 
   Fast decimal-to-binary conversions
   Author: Giovanni Motta (gim@ieee.org) 
   Made into useful program, instead of simple example code,
   by Lars Sommer, lasg@lasg.dk
*/

#include <stdio.h>
int c[32];

void fast_d2b(unsigned long x, int * c) {
	int i;

	for(i=0;i<32;i++)
		*(c++) = (x >> i) & 0x1;
}

main(int argc, char **argv) {

	if( argc==1 )
	{
		printf("Fast decimal-to-binary conversions, Author: Giovanni Motta (gim@ieee.org)\n");
		printf("Made into useful program, instead of example code by Lars Sommer, lasg@lasg.dk\n");
		printf("Usage: Give integer smaller than 4,294,967,296 as arguement\n");
		exit(1);
	}

	int k; 
	unsigned long int x;

	x=atoi(argv[1]);

	fast_d2b(x, c);
	for (k=31; k>=0; k--)
		printf("%d",c[k]);
	printf("\n");

	return 0;      
}
