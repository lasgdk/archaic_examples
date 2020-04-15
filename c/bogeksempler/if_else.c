#include <stdio.h>

main()
{
	int a,i=0;
	printf("Input integer between 1 and 50 ");
	scanf("%d",&a);
	printf("\nYou gave me the int %d. I will now calculate a little on it..\n",a);
	if (a < 1 || a > 50)
		printf("I said between 1 and 50 dumbass...\n");
	else if (a < 20)
		printf("Your int is lesser than 20\n");
	else if (a == 20)
	{
		printf("Oh! You hit my age\n");
		while (i<3)
		{
			i++;
			printf("Happy birthsday to me\n");
		}
	}
	else if (a > 20)
		printf("Your number is bigger than my age :)\n");
}

