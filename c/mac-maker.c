/*
   Code by Lars Sommer, <lasg@lasg.dk> 2006-03-27
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program. 

   	Outputs a random but legal MAC-address. Build to be called from some
	 script, to set network options at boot.

   	This is a really dirty fast hack. Please mail me, if you make it
	 more detailed / correct.

	From this file: http://anonsvn.ethereal.com/ethereal/trunk/manuf
	I noticed the following:
	Two first ciphers should be 00.
	Third cipher should be between 0 and e.
	If third cipher is 0, fourth should be between 0 and f.
	If third cipher is 1, fourth should be between 0 and 7.
	If third cipher is something else, fourth should be 0.
	The rest should be between 0 and f.
*/

#include <stdio.h>

char getrand(int);

int main(void)
{
	int i;
	char ciph[10];
	srand((unsigned int)time(NULL));
	
	ciph[0]=getrand(15);

	if( ciph[0] == '0' )
		ciph[1]=getrand(16);
	else if( ciph[0] == '1' )
		ciph[1]=getrand(8);
	else 
		ciph[1]='0';

	for(i=0;i<8;i++)
		ciph[i+2]=getrand(16);

	printf("00");
	for(i=0;i<10;i++)
	{
		if( i%2 == 0 )
			printf(":");
		printf("%c",ciph[i]);
	}
	printf("\n");

	return 0;
}


char getrand(int max)
{
	char c;
	c = rand()%max + 48;
	if( c > 57 && c < 64 )
		c=c + 39;
	return c;
}

