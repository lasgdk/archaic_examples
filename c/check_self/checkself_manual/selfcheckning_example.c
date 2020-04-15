#include <stdio.h>
#include <stdlib.h>
#define FILENAME "checksums.dat"

int main(void){
	char buf[64];
	FILE *fp;

	if( (fp=fopen(FILENAME,"r"))==NULL )
	{
		fprintf(stderr,"Error in fopen!\n");
		exit(1);
	}

	while( fgets(buf,64,fp) != NULL )
	{
		printf("%s",buf);
	}
	fclose(fp);
	return(1);

}
	
