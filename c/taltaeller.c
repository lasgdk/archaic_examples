/*
   Taeller antal forskellige cifre i en tekstfil
*/

#include <stdio.h>
#include <stdlib.h>

void display_usage(void);
int line;

main( int argc, char *argv[])
{
	int cifre[10];
	int i;
	char denne;
	FILE *fp;

	for(i=0;i<10;i++)
	{
		cifre[i]=0;
	}


	if (argc < 2)
	{
		display_usage();
		exit(1);
	}

	if (( fp = fopen( argv[1], "r" )) == NULL)
	{
		fprintf( stderr, "Fejl ved filåbning, %s!\n", argv[1]);
		exit(1);
	}

	line = 1;

	while( (denne=fgetc(fp)) != EOF)
	{
		//fprintf( stdout, "%4d:\t%s", line++, buffer );
		cifre[(int)denne-48]++;
	}

	for(i=0;i<10;i++)
	{
		printf("Der er %d  %d'ere\n",cifre[i],i);
	}


	fclose(fp);
	return(0);
}

void display_usage(void)
{
	fprintf(stderr, "\nKorrekt brug er: ");
	fprintf(stderr, "\n\nProgramnavn filnavn\n" );
}

