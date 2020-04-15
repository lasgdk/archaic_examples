#include <stdio.h>
#define len	10

int main(void){
	int array[len]={5,2,9,8,3,4,1,2,4,5};
	insertion_sort(array,len);
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d, ",array[i]);
	}
	return 0;
}

insertion_sort(int *a,int size){
	int i;
	for(i=0;i<size;i++)
	{
		insert(a,i,a[i]);
	}
}

insert(int *a,int length,int value){
	int i = length - 1;
	while (i >= 0 && a[i] > value) {
		a[i+1] = a[i];
		i--;
	}
	a[i+1] = value;
}

