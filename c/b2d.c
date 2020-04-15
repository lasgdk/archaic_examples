/* 
   Fast decimal-to-binary conversions
   Author: Giovanni Motta (gim@ieee.org) 
   Made into useful program, instead of simple example code,
   by Lars Sommer, lasg@lasg.dk
*/

#include <stdio.h>
int c[32];

void fast_d2b(unsigned long x, int * c) {
  int i;

  for(i=0;i<32;i++)
    *(c++) = (x >> i) & 0x1;
}

void fast_b2d(unsigned long int * n, int * c) {
  int i = 32;

  *n = 0;
  while(i--) {
    *n <<= 1;
    *n += *(c+i);
  }
}

main() {
  int k; 
  unsigned long int x,  y;

  printf("\nEnter an integer number");
  printf(" smaller than 4,294,967,296 : ");
  scanf("%lu", &x);

  fast_d2b(x, c);
  printf("   Bin # =");
  for (k=31; k>=0; k--)
    printf(" %d",c[k]);

  fast_b2d(&y, c);
  printf("   Dec # = %lu\n", y);
  return 0;      
}
