#include <stdio.h>

int radius, area;

main()
{
	printf("Skriv radius: ");
	scanf( "%d", &radius );
	area = (int) (3.41 * radius * radius);
	printf("\n\nArea = %d\n", area);
	return 0;
}

