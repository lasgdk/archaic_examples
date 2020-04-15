#include <stdio.h>

struct data {
	int saldo;
	char fornavn[50], efternavn[50];
} ud;

void skriv(struct data ud);

main()
{
	printf("\nIndtast for- og efternavn, adskildt af mellemrum: ");
	scanf("%s %s",ud.fornavn,ud.efternavn);
	printf("\nIndtast saldo: ");
	scanf("%d",&ud.saldo);
	skriv(ud);
	return 0;
}

void skriv(struct data ud)
{
	printf("\n\nPersonen %s %s, har %d Kr på sin konto\n",ud.fornavn,ud.efternavn,ud.saldo);
}
