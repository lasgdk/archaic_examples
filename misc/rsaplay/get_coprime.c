#include "rsaplay.h"

//Find e, a coprime to o, between 1 and o.
int get_coprime(int o)
{
	int e,i,coprime_ok=0;
	while( coprime_ok==0 )
	{
		//Try a random e, so 1<e<o
		//We only get odd numbers, and won't get 1 or o
		e = ( (rand()%((o/2)-1)+1) *2 )+1;
		printf("Testing e as %d\n",e);

		//test if the chosen e is a coprime to o
		for(i=e;i>=3;i=i-2)
		{
			coprime_ok=1;
			//This is NOT optimized!!!
			//Do we really have to loop trough so many?
			if( e%i == 0 && o%i == 0 )
			{
				printf("Bad e. %d is a common divisor..\n",i);
				coprime_ok=0;
				break;
			}
		}
	}

	return e;
}

