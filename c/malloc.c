#include <stdlib.h>
#include <stdio.h>

char count, *ptr, *p;

main()
{
	ptr = malloc(25*sizeof(char));
	if(ptr==NULL)
	{
		puts("Hukommelsesallokeringsfejl, afbryder programmet");
		exit(1);
	}
	p=ptr;
	for (count = 65; count <91; count++)
		*p++ = count;
	*p = '\0';
	puts(ptr);
	return 0;
}

