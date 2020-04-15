#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <asm/io.h>

#define BASE 0x3bc
#define TURNS 100
#define USLEEP 45000

int main(){
	int	i=0,b=0,o=0;
	if (ioperm(BASE,1,1))
		               fprintf(stderr, "Error, check permissions\n"), exit(1);
	while ( o < TURNS ) {

	while ( i < 8 ){
		b=pow(2,i);
		outb(b, BASE);
		usleep(USLEEP);
		i++;
	}
	i=0;
	o++;
	}
}
