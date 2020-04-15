/*Palindrome checker
 * root@os.dk 2005-10-23
 * This example checks if the first argument is a palindrome.
 * It returns 0 if it is, and 1 if not.
 */

#include <stdio.h>
#include "reverse_string.h"

void reverse();

int main(int argc, char **argv){
	int pal;
	if(argc==1)
		exit(1);
	char str[strlen(argv[1])];
	reverse(argv[1],str);
	pal=strcmp(str,argv[1]);
	printf("%d\n",pal);
}

