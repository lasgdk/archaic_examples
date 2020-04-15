#include <stdio.h>

main()
{
	int i=0;
	while (i<10)
	{
		printf("Vi tæller til 10. Jeg er nået til %d\n",i);
		i++;
	}
	
	do
	{
		printf("Og tæller videre til 20, hvor jeg er nået til %d\n",i);
		i++;
	} while (i<=20);
}
