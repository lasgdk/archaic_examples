#include <sys/types.h>
#include <md5.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "testfil"

main(){
	char *res;
	char buf[33];
	unsigned long filelen;
	char *filebuf;
	FILE *fp;

        if(  (fp=fopen(FILENAME,"rb"))==NULL )
        {
               fprintf(stderr,"Error in fopen!\n");
               exit(1);
	}

	fseek(fp, 0, SEEK_END);                                              
	filelen=ftell(fp);
	fseek(fp, 0, SEEK_SET);

	filebuf = (char*)malloc(filelen+1);
	if( !filebuf )
	{
		fprintf(stderr,"Error at malloc!\n");
	        fclose(fp);
		exit(1);
	}
	fread(filebuf,filelen,1,fp);

	res = MD5Data(filebuf,filelen,buf);

	printf("With MD5Data: %s\n",res);

	res = MD5File(FILENAME,buf);

	printf("With MD5File: %s\n",res);

	free(filebuf);
	fclose(fp);
	return 0;
}

