#include <stdio.h>
#include <stdlib.h>
#include "QRBG.h"
int main(int argc, char* argv[]) {
	int i,j;
	
	if( argc!=3 )
	{
		printf("Give size and times as two arguements\n");
		exit(1);
	}

	int size = atoi(argv[1]);
	int times = atoi(argv[2]);

	if( size>1024 || times>128)
	{
		printf("Too big size or times! Keep under 1024 and 128\n");
		exit(1);
	}

	byte buffer[size];

	QRBG rndService;
	rndService.defineServer("random.irb.hr", 1227);
	rndService.defineUser("username", "password");

	for(j=1;j<=times;j++)
	{
		rndService.getBytes(buffer, size);
		for(i=0;i<=size-1;i++)
		{
			printf("%x",buffer[i]);
		}
	}
}
