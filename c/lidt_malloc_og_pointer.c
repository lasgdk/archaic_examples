#include <stdio.h>
#include <stdlib.h>
int main(void){

int *mem;
mem=malloc(4);
printf("%d ",mem);
free(mem);
return(0);
}

/*
Lidt pointerstuff:
*p  ==  p[0]
*(p+1)  ==  p[1]
Hvis man l�gger een til (p+1), s� husk om p er en char, int eller andet.
*/
