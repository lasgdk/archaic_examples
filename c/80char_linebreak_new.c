//READ MAN FMT
//
//
/*Travel a line, note the last seen space.
 * When you reach char 80, change the last seen space to a linebreak.
 * If you see a linebreak before char no 80, reset char counter.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char buf[1024];
	FILE *fp;
	int i=0,j;
	int last_space=0;

	if( (fp = fopen(argv[1],"r"))==NULL )
	{
		fprintf(stderr,"Error at reading file %s\n",argv[1]);
		exit(1);
	}

	while( fgets(buf,1024,fp)!=NULL)
	{

		for(j=0;j<strlen(buf)/80;j++)
		{

		while( buf[i] != '\n')
		{
			i++;
			if( buf[i]==' ' )
			{
				last_space=i;
			}
			if( i==80 && last_space!=0 )
			{
				i=0+80*j;
				buf[last_space]='\n';
				last_space=0;
			}
		}
		i=0+80*j;
		last_space=0;
		}

		printf("%s",buf);
	}
	fclose(fp);
	return(0);
}

