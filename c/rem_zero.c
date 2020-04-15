/*
Removes zeros from the beginning of a number. Useful when you have another program, which outputs large binary numbers, alot of times with too many zeros.

Lars Sommer, lasg@lasg.dk, 2006-09-17

*/
#include <stdio.h>

main(int argc, char **argv) {
	if( argc==1 )
	{
		printf("Give number with beginning zeroes as input,\n");
		printf(" and the zeroes are removed.. :)\n");
		exit(1);
	}

int len=0,i,begin=0;
char *num;
num=argv[1];
len=strlen(num);

for (i=0;i<=len;i++){

	if (num[i] != '0')
	{
		begin=1;
	}

	if( begin==1 )
	{
		printf("%c",num[i]);
	}
}

printf("\n");

return 0;
}
