/*
Skrevet af LaSG i år 2004
Du må bruger denne kode hvor du vil, men ikke fjerne mit navn fra den.

Brugeren indtaster tre tal, som lægges sammen
*/

#include <stdio.h>

int total=0, aktuel=0, indtast;

main()
{
	while(aktuel<3)
	{
		indtast=0;
		while(indtast<1 || indtast>5000)
		{
			indtast=0;
			printf("Skriv et tal mellem 1 og 5000: ");
			scanf("%d",&indtast);
		}
		
		total = total + indtast;
		aktuel++;
	}
	printf("Dine 3 indtastninger giver sammenlagt %d\n",total);
}
