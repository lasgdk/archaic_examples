#include <stdio.h>
#include <string.h>

char *ownstrstr(char *szHaystack,char *szNeedle);

int main(void){
	char *haystack="Den gamle gartner - han ryger Partner";
	char *needle="art";
	char *hit;
	hit=ownstrstr(haystack,needle);
	printf("Strengen \"%s\" findes første gang på ",needle);
	printf("karakterplads %d i stregen \"%s\".\n",hit-haystack,haystack);
	return 0;
}

char *ownstrstr(char *szHaystack,char *szNeedle){
	int lenneedle=strlen(szNeedle);
	int lenhaystack=strlen(szHaystack);
	int i,j;
	int tjek=0;
	for(i=0;i<=(lenhaystack-lenneedle);i++)
	{
		if( szHaystack[i]==szNeedle[0] )
		{
			for(j=1;j<lenneedle;j++)
			{
				if( szHaystack[i+j]!=szNeedle[j] )
				{
					tjek=1;
					j=lenneedle;
				}
			}
			if( tjek==0 )
				return szHaystack+i;
			tjek=0;
		}
	}
	return 0;
}
