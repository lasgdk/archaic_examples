/*
   Code by Lars Sommer, <lasg@lasg.dk>
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program. 

   Program for trigging webcam via motion detector

   I've put a simple circuit with a standard motion detector and a relay,
    to my parallel port input box. This prog checks for signal from the
    motion detector, and triggers a Sandberg Nightcam webcam.

   Version 1.0 2006-09-18, its working. Build for FreeBSD 6.x
*/

#include <sys/types.h>
#include <machine/sysarch.h>
#include <stdio.h>
#include <time.h>

// This port is system specific. 0x3bd fits for IBM thinkpad.
// This is ALWAYS one higher than the normal output port.
#define INPORT 0x3bd

// The CAMBIT should be between 3 and 7, both inclusive. 
// This is the five input bits on the parallel port.
#define CAMBIT 6

#define FILENAMEBUFFERSIZE 58

int binbuf[7];
char filename[FILENAMEBUFFERSIZE];

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

void makefilename(){
	// First we mess a bit, to get a nice time of the day
	time_t curtime;
	struct tm *loctime;
	curtime=time(NULL);
	loctime=localtime(&curtime);
	// If you change this string, FILENAMEBUFFERSIZE should be changed with
	// Consider making it nicer with some sort of strlen() 
	strftime(filename,FILENAMEBUFFERSIZE, "spca5shot -j -s 640x480 -e 1 -o %y%m%d-%H%M%S.camshot.jpg",loctime);
}

int main() {
	int ind=0,i;
	FILE* dummy;
	if (dummy = fopen("/dev/io", "rw")) {

		// Do this loop forever
		while( 1 )
		{
			// Check values on the parallel port
			ind=inb(INPORT);

			// Convert the dirty decimal value to binary
			d2b(ind,binbuf);

			// If signal on the correct pin, take a photo
			if( binbuf[CAMBIT] == 1 )
			{
				makefilename();
				system(filename);
			}

			// microsleep, 1.000.000 is one sec. This is 1/10 sec:
			usleep(100000);
		}

		fclose(dummy);
	}
	else {
		printf("Cannot get IO permission. Are you root?\n");
		exit(1);
	}
	return 0;
}

