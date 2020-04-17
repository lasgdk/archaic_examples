#include "rsaplay.h"

int randprime(void)
{
	int i,count=0;
	count=rand()%(MAX-MIN);
	while(1)
	{
		for(i=MIN;i<=MAX;i++)
        	{
               		if( is_prime(i) )
	       		{
				if( count == 0 )
		      		{
			       		return i;
				}
		       		count--;
			}
		}
	}
}

