#include <stdio.h>
#include <stdlib.h>
#define CHECKSUMS_FILE "checksums.dat"
#define CHECKFILE "selfcheckning_example"
#define BYTES_PR_CHECKSUM 128

int main(void){
	char *buf;
	int *res;
	FILE *fpr,*fpw;
	int i;
	int checksums;

	unsigned long filelen;

	if( (fpw=fopen(CHECKSUMS_FILE,"wt"))==NULL )
	{
		fprintf(stderr,"Error in fopen!\n");
		exit(1);
	}
	if( (fpr=fopen(CHECKFILE,"rb"))==NULL )
	{
		fprintf(stderr,"Error in fopen!\n");
		fclose(fpw);
		exit(1);
	}

	fseek(fpr, 0, SEEK_END);
	filelen=ftell(fpr);
	fseek(fpr, 0, SEEK_SET);

	buf = (char*)malloc(filelen+1);
	if( !buf )
	{
		fprintf(stderr,"Error at malloc!\n");
		fclose(fpr);
		fclose(fpw);
		exit(1);
	}
	checksums= (filelen+1)/BYTES_PR_CHECKSUM;
	res = (int*)malloc(checksums);
	if( !res )
	{
		fprintf(stderr,"Error at malloc!\n");
		fclose(fpr);
		fclose(fpw);
		free(buf);
		exit(1);
	}

	fread(buf,filelen,1,fpr);

	for(i=0;i<checksums;i++)
		res[i]=0;

	for(i=0;i<filelen;i++)
		res[i%checksums]+=(int)buf[i];

	for(i=0;i<checksums;i++)
		fprintf(fpw,"%d\n",res[i]);

	free(buf);
	free(res);
	fclose(fpr);
	fclose(fpw);
	return(0);
}

