#include <stdio.h>

int main()
{
	  char ind;

	    while((ind = getchar()) != EOF)
		      {
			          if(ind == 'z'){
					        ind = 'a';}
				          else
						        ind++;
					      
					      
					      printf("%c",ind);
					        }
	      
	      return 0;
}

