/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include "sorting.h"

int generate_input(int len,char type){
	int i;
	static int a[LEN];

	/*
	 *The different types of are r for random, f for forward and b for backward
	 * */
	switch(type){
		case 'r':
			srand((int)time(NULL));
			for(i=0;i<len;i++)
			{
				/*
				 *IMPORTANT NOTE! This is not the optimal/secure
				 * way to generate random numbers. This is only
				 * usable in this small "for fun" program!
				 * */
				a[i]=rand() % MAXVALUE;
			}

			break;
		case 'f':
			for(i=0;i<len;i++)
				a[i]=i;
			break;
		case 'b':
			for(i=0;i<len;i++)
				a[i]=len-i-1;
			break;
		default:
			printf("Missing type of input!\n");
			exit(1);
		break;
	}

	return (int)a;
}
