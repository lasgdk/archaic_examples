#include <sys/types.h>
#include <machine/sysarch.h>
#include <stdio.h>
#include <stdlib.h>

#define INPORT 0x3bd

static inline int inb (unsigned short int port) {
	int i=0;
        __asm__ volatile ("inb %1,%0\n":"=a"(i): "d" (port) );
	return i;
}

int main() {

	int ind=0;
	FILE* dummy;
	if (dummy = fopen("/dev/io", "rw")) {

		ind=inb(INPORT);
		printf("%d\n",ind);

		fclose(dummy);
	}
	else {
		printf("Cannot get IO permission\n");
		exit(1);
	}
	return 0;
}

