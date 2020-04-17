#include <stdio.h>

int main(void)
{
	int c,count=0;
	char ciph1,ciph2;
	while ((c=getchar()) != EOF && ( count < 160 ) )
	{
		ciph1=c/16 + 48;
		ciph2=c%16 + 48;

		if( ciph1 > 57 && ciph1 < 64 )
		{
			ciph1=ciph1+39;
		}

		if( ciph2 > 57 && ciph2 < 64 )
		{
			ciph2=ciph2+39;
		}

		printf("%%%c%c",ciph1,ciph2);
		count++;
	}	
	return 0;
}

