#include <stdio.h>
#define SEK_PR_MIN 60
#define SEK_PR_TIME 3600

unsigned sekunder, minutter, timer, sekundrest, minutrest;

main()
{
	printf("\nSekundomregner!\n\n");
	printf("Indtast et antal sekunder du vil have omregnet (<65355): ");
	scanf("%d", &sekunder);

	timer = sekunder / SEK_PR_TIME;
	minutter = sekunder / SEK_PR_MIN;
	minutrest = minutter % SEK_PR_MIN;
	sekundrest = sekunder % SEK_PR_MIN;

	printf("%u sekunder er lig med ", sekunder);
	printf("%u time(r), %u minut(ter) og %u sekund(er)\n", timer, minutrest, sekundrest);

	return 0;
}

	
