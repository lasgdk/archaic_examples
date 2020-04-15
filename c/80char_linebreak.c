

LÆS man fmt
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE	256

int line;
char buffer[BUFSIZE];
int linelen=0;

void get_linelen(void);

int main( int argc, char *argv[])
{
	FILE *fp;
	int i=0;
	int j=0;

	if (argc < 2)
	{
		fprintf(stderr, "Give filename as arguement\n" );
		exit(1);
	}

	if (( fp = fopen( argv[1], "r" )) == NULL)
	{
		fprintf( stderr, "Cannot read file %s!\n", argv[1]);
		exit(1);
	}

	line = 1;

	while( fgets( buffer, BUFSIZE, fp ) != NULL)
	{
		get_linelen();
		buffer[linelen+1]='\0';

		while( i<linelen)
		{

		for(i=0;i<=linelen;i++)
		{
			if( i== 80  )
			{

		for(j=0;j<80;j++)
		{
			if( buffer[80-j] == ' ')
			{
				buffer[80-j]='\n';
				break;
			}
		}

		}
		}
		}


		printf("%s",buffer);
	}

	fclose(fp);
	return(0);
}

void get_linelen(void){
	int i;
	for(i=0;i<BUFSIZE;i++)
	{
		if( buffer[i]=='\n' )
		{
			linelen=i;
			break;
		}
	}
	printf("Linelen: %d\n",linelen);
}


