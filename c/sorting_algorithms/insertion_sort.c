/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include "sorting.h"

int insertion_sort(int *a, int len){
	int i,j,val;
	/*Run over the entire array, starting from 1, as we cannot move 0 anyway */
	for(i=1;i<len;i++)
	{
		/*Save the current a[i] in a buffer */
		val=a[i];
		/*Go through the entries before the current i, to see if our current value
		 * should move down*/
		for(j=i-1; ( j>=0 && a[j] > val ) ;j--)
		/*Move one value one step up, only overwriting the value saved in the buffer */
			a[j+1] = a[j];
		/*Re-insert the buffered value */
		a[j+1]=val;
	}
	return 0;
}

