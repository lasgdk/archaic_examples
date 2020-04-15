#include <stdio.h>
#include <string.h>

int main(void)
{
	char *ord="test",ordgaet[strlen(ord)+1],ordvist[strlen(ord)+1];
	char gaet;
	int aktuel,forsoeg=0,i;
	//ord=vaelgord();
	//ord="test";
	for(i=0;i<strlen(ord);i++)
	{
		ordvist[i]='-';
	}
	ordvist[strlen(ord)]='\0';
	
	while( (strcmp(ord,ordvist)) != 0 )
	{
		//aktuel=drejhjul()
		printf("Ordet er: %s\n",ordvist);
		printf("Indtast et bogstav du gætter på indgår i ordet.\n");
		printf("Tast 0 for at gætte på hele ordet.\n");
		gaet=0;
		gaet=getchar();
		//scanf("%c",&gaet);
		forsoeg++;

   		if( gaet=='0' )
		{
			printf("Du vil gætte på det fulde ord!\n");
			printf("Hvad tror du ordet er?: ");
			scanf("%s",ordgaet);
			if( strcmp(ord,ordgaet) == 0 )
			{
				printf("Du gættede ordet!\n");
				strcpy(ordvist,ordgaet);
			}
		}
		for(i=0;i<strlen(ord);i++)
		{
			if( gaet==ord[i] )
			{
				ordvist[i]=gaet;	
			}
		}
	}

	printf("Du gættede ordet %s i %d forsøg\n",ord,forsoeg);
	return 0;
}

