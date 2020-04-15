#include <stdio.h>

char letter = '$', array[]="Pointers are fun!", firstegn[81], *p_firstegn;

main()
{
	p_firstegn = malloc(81*sizeof(char));
	if (p_firstegn == NULL)
	{
		printf("Hukommelsesallokeringsfejl, programmet stopper\n");
		exit(1);
	}
	gets(firstegn);
	printf("\n%s", firstegn);
	printf("\n%c", letter);
	printf("\n%s", array);
	return 0;
}

