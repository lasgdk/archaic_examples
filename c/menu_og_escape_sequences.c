#include <stdio.h>
#define QUIT 3

int menuvalg(void);
void skriv_rapport(void);

main()
{
	int valg = 0;
	while(valg != QUIT)
	{
		valg = menuvalg();

		if (valg==1)
			printf("\nBip bip bip\a\a\a");
		else
		{
			if(valg==2)
				skriv_rapport();
		}
	}
	printf("Afslutter..\n");
	return 0;
}

int menuvalg(void)
{
	int valg=0;

	do
	{
		printf("\n");
		printf("\n1 - Bip tre gange");
		printf("\n2 - Skriv rapport ud på skærmen");
		printf("\n3 - Afslut");
		printf("\n");
		printf("\nTast dit valg, og tryk ENTER: ");

		scanf("%d", &valg);
	}while(valg<1 || valg >3);

	return valg;
}

void skriv_rapport(void)
{
	printf("test");
}
