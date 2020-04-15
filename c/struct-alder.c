#include <stdio.h>

struct person{
	char fornavn[20];
	char efternavn[20];
	int alder;
};

struct person liste[5];
int cnt;

main()
{
	for(cnt=0;cnt<5;cnt++)
	{
		printf("\nPerson nr. %d:\n",cnt);
		printf("\nSkriv fornavn og efternavn, adskildt af mellemrum: ");
		scanf("%s %s", liste[cnt].fornavn, liste[cnt].efternavn);
		printf("\nIndtast %s's alder: ",liste[cnt].fornavn);
		scanf("%d",&liste[cnt].alder);
		if(cnt!=5)
			printf("\nTak, så tager vi næste person...\n");
	}
	
	printf("\nNavn:\tAlder:\n");
	for(cnt=0;cnt<5;cnt++)
	{
		printf("%s %s\t%d\n",liste[cnt].fornavn,liste[cnt].efternavn,liste[cnt].alder);
	}
	return 0;
}

