#include "rsaplay.h"

//Find d, a number so (e*d)%o = 1
int get_d(int o, int e)
{
	int d,i,d_ok=0,ret1=0;
	//Which numbers returns 1, when modulus o? - The o"table"+1 does.
	ret1=o+1;
	while( d_ok==0 )
	{
		//It works, if e is a factor
		if( ret1%e == 0 )
			d_ok=1;
		else
			ret1=ret1+o;
	}
	d=ret1/e;
	return d;
}

