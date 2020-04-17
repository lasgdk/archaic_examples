//Beerware
//Lars Sommer, lasg@lasg.dk

#include <stdio.h>
#include <string.h>

int main()
{
	char *s="1612841213";
  int cpr[9]; /* til de ni første cifre */
  int grundtest; /* til grundtest */
  int last; /* sidste ciffer */
  int i;
  
  for(i=0;i<10;i++)
  {
    cpr[i] = s[i] - 48;
	printf(" CPR: %d",cpr[i]);
  }

  /* grundtest
   * ganges med 4, 3, 2, 7, 6, 5, 4, 3 og 2
   */
  grundtest = cpr[0]*4 + cpr[1]*3 + cpr[2]*2 +
	      cpr[3]*7 + cpr[4]*6 + cpr[5]*5 +
	      cpr[6]*4 + cpr[7]*3 + cpr[8]*2 + cpr[9];

printf(" GRUNDTEST: %d",grundtest);

  /* modulus 11 skal være lig sidste ciffer */ 
  if((grundtest%11) == 0)
printf("GYLDIG");
  else
    return 1;
}
