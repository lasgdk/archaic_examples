/*
GCD - Greatest Common Divisor
   */

#include <stdio.h>

int gcd_bruteforce(int x,int y);
int gcd_euclid(int x,int y);

int main(void)
{
	int a,b,c;
	printf("This program computes the greatest common divisor of two inputs.\n");
	printf("Give two integers as inputs....  ");
	scanf("%d",&a);
	scanf("%d",&b);

	//If a is greater than b, swap them.
	if( b<a )
	{
		c=b;
		b=a;
		a=c;
	}

	printf("\nI can compute using bruteforce (1) or Euclids algoritm (2).\n");
	printf("Give me either 1 or 2: ");
	scanf("%d",&c);
	switch (c){
		case 1:
			c=gcd_bruteforce(a,b);	
			break;
		case 2:
			c=gcd_euclid(a,b);	
			break;
		default:
			printf("Typing 1 or 2 was too hard for you eh?\n");
			return 1;
			break;
	}
	printf("\nThe greatest common divisor of %d and %d is computed to %d\n",a,b,c);
	return 0;
}

int gcd_bruteforce(int x,int y) 
{
	int z=y;

	while( (x%z != 0) || (y%z != 0) )
	{
		z--;
	}
	return z;
}

int gcd_euclid(int x,int y)
{
	int r=1;

	while(1)
	{
		r=y%x;
		if( r == 0 )
		{
			return y;
		}
		x=y;
		y=r;
	}
}

