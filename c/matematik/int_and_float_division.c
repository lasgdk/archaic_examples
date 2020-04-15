#include <stdio.h>

main()
{
	int a,b,ave_int;
	float ave_float;
	a=10;
	b=3;
	ave_int = a/b;
	ave_float = a/b;
	
	printf("10/3, as integer and float\n");
	printf("Integer:\t%d\n",ave_int);
	printf("Float:\t\t%f\n",ave_float);
}
