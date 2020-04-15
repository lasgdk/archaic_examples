/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include "sorting.h"

int merge_sort(int *res,int len){
	/*Left and right must have length LEN/2+1, as if they only had LEN/2
	 * a problem occur when an array has unequal length  */
	int left[LEN/2+1],right[LEN/2+1];
	int mid,leftlen,rightlen;
	int i;
	if (len<=1)
		return 0;

	mid = len/2;
	leftlen=mid;
	rightlen=len-mid;
	if(DEBUG)
		printf("len: %d, mid: %d, leftlen: %d, rightlen: %d\n",len,mid,leftlen,rightlen);
	/*Inserting values into the left array  */
	for(i=0;i<mid;i++)
	{
		if(DEBUG)
			printf("Inserting %d into left\n",res[i]);
		left[i]=res[i];
	}
	/*Inserting values into the right array  */
	for(i=mid;i<len;i++)
	{
		if(DEBUG)
			printf("Inserting %d into right\n",res[i]);
		right[i-mid]=res[i];
	}

	if (DEBUG)
	{
		printf("Printing left and right: ");
		for(i=0;i<leftlen;i++)
			printf("left[%d] = %d,  ",i,left[i]);
		for(i=0;i<rightlen;i++)
			printf("right[%d] = %d,  ",i,right[i]);
		printf("\n");
	}

	if (DEBUG)
		printf("Calling merge_sort for the left\n");
	merge_sort(left,leftlen);
	if (DEBUG)
		printf("Calling merge_sort for the right\n");
	merge_sort(right,rightlen);

	if (DEBUG)
		printf("Calling merge\n");
	merge(res,left,right,leftlen,rightlen);

	return 0;
}

int merge(int *a,int *left,int *right, int leftlen, int rightlen){
	int i;
	int apos=0,leftpos=0,rightpos=0;
	while( leftpos < leftlen && rightpos < rightlen )
	{
		if( left[leftpos] < right[rightpos] )
			a[apos++] = left[leftpos++];
		else
			a[apos++] = right[rightpos++];
	}
	while( leftpos < leftlen )
		a[apos++] = left[leftpos++];
	while( rightpos < rightlen )
		a[apos++] = right[rightpos++];

	if (DEBUG)
	{
		printf("Finishing merge with a equal to: ");
		for(i=0;i<rightlen+leftlen;i++)
			printf("%d ",a[i]);
		printf("\nFinishing merge with left equal to: ");
		for(i=0;i<leftlen;i++)
			printf("%d ",left[i]);
		printf("\nFinishing merge with left right to: ");
		for(i=0;i<rightlen;i++)
			printf("%d ",right[i]);
		printf("\n");
	}
	return 0;
}
