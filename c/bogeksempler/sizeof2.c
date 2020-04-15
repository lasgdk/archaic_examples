#include <stdio.h>

main(){
	int a,b;

	a=2147483648;
	b=sizeof(a);
	printf("%d og %d\n",a,b);
}

