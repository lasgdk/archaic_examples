#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
        if(argc==1)
                exit(1);
	char *str=argv[1];
	int i;
	unsigned long dec=0;
	for(i=0;i<=(strlen(str)-1);i++)
	{
		if(str[strlen(str)-1-i]>=97 && str[strlen(str)-1-i] <=102)
			dec=dec+ (str[strlen(str)-1-i]-87)*(int)pow(16,i);
		else
			dec=dec+ (str[strlen(str)-1-i]-48)*(int)pow(16,i);
	}
	printf("%d\n",dec);
	return 0;
}

