/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include "sorting.h"

int main(void){
	int len=LEN;
	int *a;
	a = (int*)generate_input(len,'r');
	parray(a,len);

/*
  	insertion_sort(a,len);
	heap_sort(a,len);
*/
	merge_sort(a,len);

	parray(a,len);
	return 0;
}

int parray(int *a, int len){
	int i;
	printf("The current array is:\n");
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

