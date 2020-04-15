#include <sys/types.h>
#include <md5.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "checkself"

/**
 * \file checkself.c
 * \author Lars Sommer, lasg@lasg.dk
 * \date 08-11-28
 * \brief Example of using MD5 to check program integrity
 *
 * This example shows how to check program integrity using MD5 sums located
 *  inside the program itself. This is achieved by checking all program code
 *  before and after the actual check strings. 
 *
 * The concept is to be used in a test package for space testing
 *  microcontrollers for errors at high radiation. It could be used for
 *  copy/crack protection as well, but it completely insecure, which perhaps
 *  will be demonstrated later
 *
 * Please note that the MD5 sums will differ from systems and compilers, so
 *  you'll have to fix the actual correct check strings manually.
 * */

/**
 * The main function contains all the code
 * */
int main(void){
	/**
	 * Generally res1, buf1 and correct1 corresponds to the first MD5 
	 *  string. And res2, buf2 and correct2 to the second string
	 *  */
	char *res1;
	char *res2;
	char buf1[33];
	char buf2[33];
	char *correct1;
	char *correct2;

	/**
	 * offset and len is taken from output at "strings -t d filename"
	 * */
	res1 = MD5FileChunk(FILENAME,buf1,0,1896);
	res2 = MD5FileChunk(FILENAME,buf2,1964,0);

	/**
	 * \todo These strings res and correct, should be concatenated
	 * */

	/**
	 * The calculated strings are printed for debugging purposes
	 * */
	printf("MD5 part 1: %s\n",res1);
	printf("MD5 part 2: %s\n",res2);

	correct1="76fdaa9bd158379cf35c23eda222ed02";
	correct2="2c860439aa11ac292fade6e1d6591e8b";
	printf("Correct: %s\n",correct1);
	printf("Correct: %s\n",correct2);

	/**
	 * If the strings are matching, everything is okay
	 * */
	if( !strncmp(res1,correct1,32) && !strncmp(res2,correct2,32) )
		printf("Ok, integrity confirmed!\n");
	else
		printf("Integrity check failed. Program was tampered!\n");

	return 0;
}

