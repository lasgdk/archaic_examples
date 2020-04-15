/*
fillister lister en tekstfil, med linjenumre.
*/

#include <stdio.h>
#include <stdlib.h>

int line;

main( int argc, char *argv[])
{
	char buffer[256];
	FILE *fp;

	if (argc < 2)
	{
		fprintf(stderr, "\nKorrekt brug er: ");
		fprintf(stderr, "\n\nfillister filnavn.ext\n" );
		exit(1);
	}

	if (( fp = fopen( argv[1], "r" )) == NULL)
	{
		fprintf( stderr, "Fejl ved filåbning, %s!\n", argv[1]);
		exit(1);
	}

	line = 1;

	printf("Listing of file %s\n---------------\n",argv[1]);

	while( fgets( buffer, 256, fp ) != NULL)
		fprintf( stdout, "%4d:\t%s", line++, buffer );

	fclose(fp);
	return(0);
}

