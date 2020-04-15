#include <stdio.h>
#include <math.h>

// compile with -lm

int main(void)
{

	int a,b,c,d,x1,x2;
	printf("Andengradsligningsløser\n");
	printf("Løser ligninger på formen ax^2+bx+c=0\n");
	printf("Indtast a, b og c med mellemrum imellem: ");
	scanf("%d %d %d",&a,&b,&c);
	
	d=(b*b)-(4*a*c);

	if( d<0 )
	{
		printf("Determinanten er negativ, hvorfor der ingen løsninger er.\n");
		return 0;
	}

	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);

	if( x1==x2 )
	{
		printf("Determinanten er 0, hvormed vi har een løsning, som er %d\n",x1);
	}
	else{
		printf("Determinanten er %d, og løsningerne er %d og %d\n",d,x1,x2);
	}

	return 0;
}

