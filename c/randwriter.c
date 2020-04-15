#include <stdio.h>

main(void)
{
	char filnavn[]="testfil.txt";
	int i;
	FILE *ofp;

	srand((unsigned int) time(NULL));

	if (( ofp = fopen( filnavn, "w" )) == NULL)
	{
		fprintf( stderr, "Fejl ved filåbning!\n");
		exit(1);
	}

	for(i=0;i<=500;i++)
		fprintf( ofp, "%d",rand() );

	fclose(ofp);
	return(0);
}

