#include <stdio.h>

main()
{
	int i=0;
	while (i<10)
	{
		printf("Vi t�ller til 10. Jeg er n�et til %d\n",i);
		i++;
	}
	
	do
	{
		printf("Og t�ller videre til 20, hvor jeg er n�et til %d\n",i);
		i++;
	} while (i<=20);
}
