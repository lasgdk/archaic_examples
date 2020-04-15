/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include "sorting.h"

int heap_sort(int *a, int len){
	int i;
	int tmp=0;
	int heapsize=len;

	/*Start by building the heap */
	build_max_heap(a,len);
	printtree(a,len);

	for(i=len-1;i>0;i--)
	{
		if (DEBUG)
			printf("Putting %d out of the heap, into position a[%d]\n",a[0],i);
		/*Take the root out of the heap, to the end, which will build
		 * up the resulting array */
		tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;
		if (DEBUG)
			parray(a,len);

		/*Reduce the heap, which also increases the final array */
		heapsize--;
		if (DEBUG)
			printf("heapsize reduced to %d\n",heapsize);
		/*As we just moved the root away, the tree is not max heapified
		 * any longer. Fix it by running max_heapify again. */
		max_heapify(a,heapsize,0);
	}
	return 0;
}

int build_max_heap(int *a, int len){
	int i=0;
	if (DEBUG)
		printf("len: %d, i: %d\n",len,i);
	/*We build the heap by running through all the values from the 
	 * buttom and up, and max_heapifying each one. */
	for(i=(len);i>0;i--)
	{
		if (DEBUG)
			printf("build_max_heap calling max_heapify with i: %d\n",i-1);
		max_heapify(a,len,i-1);
	}
	return 0;
}

int max_heapify(int *a,int len, int entry){
	int left=2*entry+1;
	int right=(2*entry+1)+1;
	int child=0,tmp=0;
	printtree(a,len);
	/* */
	if( left>=len )
	{
		if (DEBUG)
			printf("The bottom is reached!\n");
		return 0;
	}
	/*If an entry only have one child, we just set the right to the
	 * same value as left, even though right does not exist.
	 * It is legal as we count left as more important than right at [*1] */
	if( right>=len )
	{
		if (DEBUG)
			printf("The current entry: %d, does not have a right leaf\n",entry);
		right=left;
	}
	if (DEBUG)
		printf("left = %d, right = %d, entry = %d\n",left,right,entry);
	/*[*1] If left child is equal to, or greater than, it will be chosen
	 * over the right */
	if( a[left] >= a[right] )
	{
		if (DEBUG)
			printf("child set to left, which is %d\n",left);
		child=left;
	}
	else
	{
		if (DEBUG)
			printf("child set to right, which is %d\n",right);
		child=right;
	}
	if( a[entry] < a[child] )
	{
		if (DEBUG)
			printf("Swapping a[entry] (%d) and a[child] (%d)\n",a[entry],a[child]);
		tmp=a[entry];
		a[entry]=a[child];
		a[child]=tmp;

		if (DEBUG)
			printf("max_heapify calling itself...\n");
		max_heapify(a,len,child);
	}
	return 0;
}

/*
 *This is just a helping function to print a (semi) nice tree. It will do
 * nothing if DEBUG is disabled.
 * */
int printtree(int *a, int len){
	int i,j;
	int nextbreak=1;
	int currentrow=1;
	if( !DEBUG )
		return 0;
	printf("\n The current tree:");
	for(i=0;i<len;i++)
	{
		if( i+1 == nextbreak )
		{
			printf("\n");
			nextbreak*=2;
			currentrow++;
		}
		/*
		 *This spacing amount COULD make the tree nicer.
		 * Try different amounts of whitespace.
		 * */
		for(j=0;j<(len/currentrow)*2;j++)
		{
			printf(" ");
		}
		printf("(%d: %d)",i,a[i]);
	}
	printf("\n");
	printf("\n");
	return 0;
}
