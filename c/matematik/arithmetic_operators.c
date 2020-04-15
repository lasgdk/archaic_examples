#include <stdio.h>

main()
{
	int a,b,c,d,e,f,g,h;

	a=10;
	b=10;
	c=10;
	d=10;
	e=10;
	f=10;
	g=10;
	h=10;

	printf("a+=10 is equivalent to a=a+10\n");
	a+=10;
	b=b+10;
	printf("Calculation one gives %d, and two gives %d\n",a,b);
	printf("Now we test with -, * and /\n");
	c-=10;
	d=d-10;
	e*=10;
	f=10*f;
	g/=2;
	h=h/2;
	printf("Calculations:\nShorthand:\tEquivalent:\n");
	printf("%d\t%d\n%d\t%d\n%d\t%d\n",c,d,e,f,g,h);

}
