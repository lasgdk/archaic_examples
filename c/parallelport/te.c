#include <sys/types.h>
#include <machine/sysarch.h>
#include <stdio.h>
#include <stdlib.h>

#define BASEPORT 0x3bc

static inline void outb (unsigned short int port, unsigned char val) {
        __asm__ volatile ("outb %0,%1\n"::"a" (val), "d" (port) );
}


int main(int argc, char *argv[]) {
	FILE* dummy;
	if (dummy = fopen("/dev/io", "rw")) {

//		outb (BASEPORT, 3);
//		sleep(1);

int c,s;
c=atoi(argv[1]);
s=atoi(argv[2]);

		outb (BASEPORT, c);
		usleep(s);

		fclose(dummy);
	}
	return 0;
}

