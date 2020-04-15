#include <stdio.h>
int var=1;
int *ptr;

main()
{
	ptr=&var;
	printf("\nDirekte adgang, var = %d", var);
	printf("\nIndirekte adgang, var = %d", *ptr);

	printf("\nAdressen til var = %d", &var);
	printf("\nAdressen til var via ptr = %d", ptr);

	return 0;
}

