
/*
   Code by Lars Sommer, <lasg@lasg.dk>
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program. 
*/

#include <stdio.h>
void func(void)
{
	while( 1 )
	{
	printf("Hej\n");
	sleep(1);
	}
}
int main(void)
{
printf("start:");

	func();

while( 1 )
{
printf("hej2\n");
sleep(1);
}
	return 0;
}

