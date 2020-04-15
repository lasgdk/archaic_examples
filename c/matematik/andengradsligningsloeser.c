#include <stdio.h>
#include <math.h>

// compile with -lm

int main(void)
{

	int a,b,c,d,x1,x2;
	printf("Andengradsligningsl�ser\n");
	printf("L�ser ligninger p� formen ax^2+bx+c=0\n");
	printf("Indtast a, b og c med mellemrum imellem: ");
	scanf("%d %d %d",&a,&b,&c);
	
	d=(b*b)-(4*a*c);

	if( d<0 )
	{
		printf("Determinanten er negativ, hvorfor der ingen l�sninger er.\n");
		return 0;
	}

	x1=(-b+sqrt(d))/(2*a);
	x2=(-b-sqrt(d))/(2*a);

	if( x1==x2 )
	{
		printf("Determinanten er 0, hvormed vi har een l�sning, som er %d\n",x1);
	}
	else{
		printf("Determinanten er %d, og l�sningerne er %d og %d\n",d,x1,x2);
	}

	return 0;
}

