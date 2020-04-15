/*
Skrevet af LaSG i år 2004
Du må bruger denne kode hvor du vil, men ikke fjerne mit navn fra den.

Plotter 10 gange 10 X'er på skærmen.
*/

#include <stdio.h>

int x,y;

main()
{
	for (x=0; x<10; x++, printf("\n"))
		for (y=0; y<10; y++)
			printf("X");
	return 0;
}

