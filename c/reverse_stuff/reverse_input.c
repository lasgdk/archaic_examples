/* Reverse input
 * root@os.dk 2005-10-23
 * Takes a string as argument, and returns a reversed version of the string
 */

#include <stdio.h>
#include "reverse_string.h"

void reverse();

int main(int argc, char **argv){
	if(argc==1)
		exit(1);
	char str[strlen(argv[1])];
	reverse(argv[1],str);
	printf("%s\n",str);
}

