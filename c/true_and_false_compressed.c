/*
Simple true_false stuff
By Lars Sommer
*/

#include <stdio.h>

main()
{
	int a=0,b=5;
	if (a)
		printf("This should not be printed\n");
	if (b)
		printf("I say hello if b is set to other than 0\n");
	if (a && b)
		printf("a AND b\n");
	if (a || b)
		printf("a OR b\n");
	if (!a)
		printf("if NOT a. which is true.. :)\n");

	/* let us play a little */
	int c=0,d=1,e,f;
	printf("Look at the source, give me a 0 or 1, and calculate the result before pressing return. ");
	scanf("%d",&f);
	if (c!=d && f || f == 0)
		if (f==1||f!=1)
		{
			e=f;
			f=d;
			b=f;
			a=e;
			f=a;
			if (e!=1&&d)
				printf("foo\n");
			else if (b&&!c&&e)
				printf("bar\n");
		}
}
