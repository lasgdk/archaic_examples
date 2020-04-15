#include <stdio.h>

int pris, *p_pris;

main()
{
	p_pris = &pris;
	pris = 100;
	printf("Værdi\tAdresse\n");
	printf("%d\t%d\n",pris,&pris);
	printf("%d\t%d\n",*p_pris,p_pris);
	pris = 0;
	*p_pris = 100;
	printf("%d\t%d\n",pris,&pris);
	printf("%d\t%d\n",*p_pris,p_pris);

	printf("Værdi plus adresse giver %d\n",p_pris + pris / sizeof(int));
	return 0;
}
