/*
   Code by Lars Sommer, <lasg@lasg.dk>
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program. 

   Program for decoding 5 bit parallel port input
*/

#include <sys/types.h>
#include <machine/sysarch.h>
#include <stdio.h>
#include <time.h>

// This port is system specific. 0x3bd fits for IBM thinkpad.
// This is ALWAYS one higher than the normal output port.
#define INPORT 0x3bd

int binbuf[7];

// We have to do some inline assembler magick. 
// Don't know if this is a perfect method, but it works for me! :)
static inline int inb (unsigned short int port) {
	int i=0;
        __asm__ volatile ("inb %1,%0\n":"=a"(i): "d" (port) );
	return i;
}

// Decimal to Binary converter
void d2b(int dec, int *binbuf){
	int i;
	for(i=0;i<7;i++)
		//Giovanni Motta (gim@ieee.org) did this nice line:
		*(binbuf++)=(dec>>i) & 0x1;
}

int main() {
	int ind=0,i;
	FILE* dummy;
	if (dummy = fopen("/dev/io", "rw")) {

			// Check values on the parallel port
			ind=inb(INPORT);

			// Convert the dirty decimal value to binary
			d2b(ind,binbuf);

			// If signal on the correct pin, take a photo
			if( binbuf[CAMBIT] == 1 )
			{
			}

		fclose(dummy);
	}
	else {
		printf("Cannot get IO permission. Are you root?\n");
		exit(1);
	}
	return 0;
}

