/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include <stdio.h>

int a1[]={2,4,6,8};
int a2[]={3,5,6,7};

int merge(void){
	int i=0,j=0,k=0;
	printf("The input lists: \n");
	printf("List 1: ");
	for(i=0;i<=3;i++)
		printf("%d ",a1[i]);
	printf("\nList 2: ");
	for(i=0;i<=3;i++)
		printf("%d ",a2[i]);
	printf("\n");

	//int reslen=len(a1)+len(a2);
	int reslen=4+4;
	int res[reslen];

	for(i=0;i<=reslen-1;i++)
	{
		if(( a1[j] < a2[k] ))
		{
			res[i]=a1[j];
			printf("Putting number %d from list 1 into pos %d\n",a1[j],i);
			j++;
		}
		else{
			res[i]=a2[k];
			printf("Putting number %d from list 2 into pos %d\n",a2[k],i);
			k++;
		}
	}
	printf("The merged list: ");
	for(i=0;i<=reslen-1;i++)
		printf("%d ",res[i]);
	printf("\n");
	
	return 0;
}

int main(void){
	merge();
	return 0;
}
