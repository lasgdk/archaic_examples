#include <stdio.h>

struct person{
	char type[50];
	int pris;
} tabel[5] = {
	"Fisk", 42,
	"Kaffe", 12,
	"Computer", 666,
	"Slave", 34,
	"Lommeuld", 0
	}, *p_person;

int cnt;

main()
{
	p_person = tabel;
	printf("\nPrislisten fremstillet uden pointeren\n");	
	for(cnt=0;cnt<5;cnt++)
	{
		printf("På adresse %d starter %s, der koster %d Græske Kroner\n",p_person, tabel[cnt].type, tabel[cnt].pris);
		p_person++;
	}

	p_person = tabel;
	printf("\n\n");
	printf("\nPrislisten fremstillet med pointeren\n");	
	for (cnt=0;cnt<5;cnt++)
	{
		printf("På adresse %d starter %s, der koster %d Græske Kroner\n",p_person, p_person->type, p_person->pris);
		p_person++;
	}

	return 0;
}
