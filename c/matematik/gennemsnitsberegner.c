#include <stdio.h>

int antal=0, tal[26], nu=1;
float gennemsnit, total=0;

main()
{
	printf("\n");
	printf("Gennemsnitsberegner\n");

	while(antal<2 || antal>25)
	{
		printf("\nIndtast hvor mange tal der skal beregnes gennemsnit af (2-25): ");
		scanf("%d",&antal);
	}
	while(nu<=antal)
	{
		tal[nu]=-1;
		while(tal[nu]<0 || tal[nu]>65355)
		{
			printf("\nIndtast tal nr. %d (0-65355): ",nu);
			scanf("%d",&tal[nu]);
		}
		total = total + tal[nu];
		nu++;
	}
	gennemsnit = total / antal;
	printf("\nGennemsnittet af tallene ");
	nu=1;
	for (nu=1;nu<antal+1;nu++)
		printf("%d, ",tal[nu]);
	printf(" er %f\n",gennemsnit);
	return 0;
}
