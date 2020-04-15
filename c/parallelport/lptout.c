
/*
 * Simple parallel port output control program for Linux
 * Written and copyright by Tomi Engdahl 1998
 * (e-mail: tomi.engdahl@hut.fi)
 *
 * The program output the data value to PC parallel port data pins
 * (default lpt1 I/O address 0x378). The data values are given as the
 * command line parameter to the program. The number can be
 * in decimal (0..255) or hexadecimal format (0x00..0xFF).
 *
 */

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <asm/io.h>
#include <sys/io.h>

#define base 0x03bc           /* printer port base address */
//03bc-03be : parport0

main(int argc, char **argv)
{                    
  int value;

  if (argc!=2)
    fprintf(stderr, "Error: Wrong number of arguments. This program needs one argument which is number between 0 and 255.\n"), exit(1);
  if (sscanf(argv[1],"%i",&value)!=1)
    fprintf(stderr, "Error: Parameter is not a number.\n"), exit(1);
  if ((value<0) || (value>255))
    fprintf(stderr, "Error: Invalid numeric value. The parameter number must be between 0 and 255\n"), exit(1);
  if (ioperm(base,1,1))
    fprintf(stderr, "Error: Couldn't get the port at %x\n", base), exit(1);

  outb((unsigned char)value, base);
}                                            



