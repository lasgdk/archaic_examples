/*
* Pin bits (numbered at female end)
*  outb(8, x)   = pin 5      UNUSED
*  outb(16, x)  = pin 6      Forward
*  outb(32, x)  = pin 7      Reverse
*  outb(64, x)  = pin 8      Left
*  outb(128, x) = pin 9      Right
*  outb(80, x)  = pin 6 & 8  FORWARDLEFT
*  outb(144, x) = pin 6 & 9  FORWARDRIGHT
*  outb(96, x)  = pin 7 & 8  REVERSELEFT
*  outb(160, x) = pin 7 & 9  REVERSERIGHT
*/

#include <stdio.h>
#define BASEPORT 0x3bc

static inline void outb (unsigned short int port, unsigned char val) {
        __asm__ volatile ("outb %0,%1\n"::"a" (val), "d" (port) );
}

int main()
{


 FILE* dummy;
        if (dummy = fopen("/dev/io", "rw")) {



void forward( char key ){
	outb (BASEPORT, 16);
	usleep(10000);								/* Sleep for a while (100 ms) */
}

void reverse( char key ){
	outb (BASEPORT, 32);
	usleep(10000);
}

void left( char key ){
	outb (BASEPORT, 64);
	usleep(10000);
}

void right( char key ){
	outb (BASEPORT, 128);
	usleep(10000);
}

void forwardleft( char key ){
	outb (BASEPORT, 80 );
	usleep(10000);
}

void forwardright( char key ){
	outb (BASEPORT, 144 );
	usleep(10000);
}

void reverseleft( char key ){
	outb (BASEPORT, 96);
	usleep(10000);
}

void reverseright( char key ){
	outb (BASEPORT, 160);
	usleep(10000);
}


void stop( char key ){
	outb (BASEPORT, 0);
	usleep(10000);
}

void end () {									/* The Beggining of the end.... */
	outb (BASEPORT, 0);
	usleep(10000);
	exit(0);								/* Buh bye */
}


char i[1];

while(1==1){

	read(0,&i[0],1);							/* read one char from the buffer */
	printf("\nu pressed %c\n", i[0]);
	if (i[0] == '8') { forward(i[0]); }
	if (i[0] == '2') { reverse(i[0]); }
	if (i[0] == '4') { left(i[0]); }
	if (i[0] == '6') { right(i[0]); }
	if (i[0] == '7') { forwardleft(i[0]); }
	if (i[0] == '9') { forwardright(i[0]); }
	if (i[0] == '1') { reverseleft(i[0]); }
	if (i[0] == '3') { reverseright(i[0]); }
	if (i[0] == '5') { stop(i[0]); }
	if (i[0] == 'q') { end(); }

}

}
}
