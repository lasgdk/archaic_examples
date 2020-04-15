#include <time.h>
#include <stdio.h>

main()
{
int a;

gettimeofday(&a, NULL);

printf("%d",a);
}

