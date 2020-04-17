#include "rsaplay.h"

int main(void)
{
	srand((unsigned int) time(NULL));
	unsigned long int p,q,n,o,e,d,m,m2,c;
	p=randprime();
	q=randprime();
	while( p==q )
	{
		q=randprime();
	}
	printf("Setting these beginning primes:\np: %d\nq: %d\n",p,q);
	n=p*q;
	printf("n is set to p*q:\nn: %d\n",n);
	o=(p-1)*(q-1);
	printf("Setting o to (p-1)*(q-1):\no: %d\n",o);
	e=get_coprime(o);
	printf("Found this coprime, e, to o:\ne: %d\n",e);
	d=get_d(o,e);
	printf("Found this d, so (e*d)%%o = 1:\nd: %d\n",d);

	for(m=2;m<10;m++)
	{
		printf("Encrypting message m=%d\n",m);
		c=pow(m,e);
		c=c%n;
		printf("Into cyphertext c=%d\n",c);
		m2=pow(c,d);
		m2=m2%n;
		printf("And decrypting back into m2=%d\n",m2);
		printf("\n");
	}

	return 0;
}
