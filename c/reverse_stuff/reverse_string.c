/*Reverse string function
 * root@os.dk 2005-10-23
 * Function which returns a string reversed. 
 * To be used in reverse_input.c and palindrome.c
 */

#include <stdio.h>
#include "reverse_string.h"

void reverse(before,after)
char *before, *after;	
{
	int len=strlen(before),down,up;
	for(down=len -1, up=0; down>=0; down--,up++)
		after[up] = before[down];
	after[len] = NULL;
}

