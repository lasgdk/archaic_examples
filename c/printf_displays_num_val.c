#include <stdio.h>

int a=2, b=10, c=50;
float f=1.23, g=42.666, h=-55.55;

main()
{
	printf("\nDecimalv�rdier uden tab: %d %d %d", a,b,c);
	printf("\nDecimalv�rdier uden tab: \t%d \t%d \t%d", a,b,c);

	printf("\nTre flydere p� linje: \t%f\t%f\t%f",f,g,h);
	printf("\nTre flydere p� linjer: \n\t%f\n\t%f\n\t%f",f,g,h);

	printf("\nRaten er %f%%",f);
	printf("\nResultatet af %f/%f = %f\n", g, f, g/f);

	return 0;
}


