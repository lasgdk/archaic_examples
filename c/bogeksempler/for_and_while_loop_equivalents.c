/*
Example by Lars Sommer
The most common while loop is to do the same again and again, counting a counter integer one up per loop. 
This is simplifyed with the for loop
*/

#include <stdio.h>

main()
{
	int i;

	/* The for loop is just a simplicity solution for the most common while loop */
	for (i=0; i<=10; i++)
		printf("Nu er i lig med %d\n",i);

	/* This is exactly the same thing, with the while loop, which takes more space and lines. */
	i=0;
	while (i <=10)
	{
		printf("Nu er i lig med %d\n",i);
		i++;
	}
}
