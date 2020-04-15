#include <stdio.h>

main(){
	printf("int\t%d\n",sizeof(int));
	printf("short int\t%d\n",sizeof(short int));
	printf("long int\t%d\n",sizeof(long int));

	printf("char\t%d\n",sizeof(char));
	printf("float\t%d\n",sizeof(float));
	printf("double\t%d\n",sizeof(double));
	printf("long double\t%d\n",sizeof(long double));

	return 0;
}
