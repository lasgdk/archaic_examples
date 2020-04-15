#include <stdio.h>

unsigned int f, x;
unsigned int fakultet(unsigned int a);

main()
{
	puts("Indtast et tal (1-8): ");
	scanf("%d", &x);

	if(x>8 || x<1)
		printf("Mellem 1 og 8 din spade");
	else
	{
		f = fakultet(x);
		printf("%u fakultet er lig %u\n", x, f);
	}

	return 0;
}

unsigned int fakultet(unsigned int a)
{
	if (a == 1)
		return 1;
	else
	{
		a *= fakultet(a-1);
		return a;
	}
}
