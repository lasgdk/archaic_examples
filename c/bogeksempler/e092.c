#include <stdio.h>

int data[10], *p_data;

main()
{
	p_data = data;
	data[3]=100;
	printf("\n%d",data[3]);
	data[3]=0;
	printf("\n%d",data[3]);
	*(p_data + 3 )= 100;
	printf("\n%d\n",data[3]);
	return 0;
}

