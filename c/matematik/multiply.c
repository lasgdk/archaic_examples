#include <stdio.h>

int a,b,c;
int product(int x, int y);

main()
{
	printf("Tast et nummer mellem 1 og 100: ");
	scanf("%d", &a);

	printf("Tast et nummer mellem 1 og 100 mere: ");
	scanf("%d", &b);

	c = product(a,b);
	printf("%d gange %d er %d\n",a,b,c);

	return 0;
}

int product(int x, int y)
{
	return (x * y);
}

