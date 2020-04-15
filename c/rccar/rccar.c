/*
* rccar.c: lpt port control of a radio controlled car
* By: 	    Shaun Bowman Sept. 2003, shaun_bowman@hotmail.com <- engr 
student, needs work!
*
* Notes: This program is unlikely to be ready-2-port because of the ioctl 
method
*	  of changing terminal settings. This program was written so i could
*	  control a tiny 10$ remote control car (and to procrastinate homework).
*	  The lpt port pins (6,7,8,9) are used to control Forward, Reverse, Left
*	  and Right in the controller. In addition to this program, I had to build
*	  a simple circuit to bypass the buttons on the remote control. This is
*	  because even in the low state, the Control and Ground pins still form a
*	  complete circuit.
*
*	  Crude Diagram (1 for each button):
*
*	  GrndPin(18-25)   PinX(5-9)
*		|		|			   T1: NPN transistor, i used 2N222
*		|		|
*		|		L---R1--R2--R3		R1-R3: Resistors, i didn't have
*		|	 T1:		     |	               ones with high enough
*		|--------|\		     |                 resistance, so i had to use
*		|        | ------------------                  3. Total R ~= 100k ohm's
*               |    |---|/(<-collector pin)
*		|    |
*      -ButtnLead  +ButtnLead
*
* Compile with: gcc -O2 -o rccar rccar.c (must be root)
*
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
#include <unistd.h>
#include <asm/io.h>
#include <string.h>
#include <libio.h>

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define LPT1PORT 0x378 								/* lpt1 */

int main()
{

struct termios oldT, newT; 							/* create our termios identifiers, uphere because C++ is retarted*/

void forward( char key ){
	outb(16, LPT1PORT);							/* Set pin 9 to high */
	usleep(10000);								/* Sleep for a while (100 ms) */
}

void reverse( char key ){
	outb(32, LPT1PORT);
	usleep(10000);
}

void left( char key ){
	outb(64, LPT1PORT);
	usleep(10000);
}

void right( char key ){
	outb(128, LPT1PORT);
	usleep(10000);
}

void forwardleft( char key ){
	outb(80, LPT1PORT);
	usleep(10000);
}

void forwardright( char key ){
	outb(144, LPT1PORT);
	usleep(10000);
}

void reverseleft( char key ){
	outb(96, LPT1PORT);
	usleep(10000);
}

void reverseright( char key ){
	outb(160, LPT1PORT);
	usleep(10000);
}


void stop( char key ){
	outb(0, LPT1PORT);							/* Set the data signals (D0-7) of the port to all low (0) */
	usleep(10000);
}

void end () {									/* The Beggining of the end.... */
	outb(0, LPT1PORT);
	usleep(10000);
	if (ioperm(LPT1PORT, 3, 0)) {perror("ioperm"); exit(1);}		/* We don't need the port anymore */
	ioctl(0,TCSETS,&oldT);							/* Better set the terminal back to normal... :-) */
	exit(0);								/* Buh bye */
}


if (ioperm(LPT1PORT, 3, 1)) {perror("ioperm"); exit(1);}			/* Get access to the ports */

ioctl(0,TCGETS,&oldT); 								/* get current terminal mode */
newT=oldT; 									/* copy it into our new structure */
newT.c_lflag &= ~ECHO;								/* toggle echo */
newT.c_lflag &= ~ICANON;							/* toggle no line delimination */
ioctl(0,TCSETS,&newT);								/* initialize our new terminal mode */
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

/* end of rccar.c */

