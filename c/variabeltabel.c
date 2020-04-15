/*
Skrevet af LaSG i år 2004
Du må bruger denne kode hvor du vil, men ikke fjerne mit navn fra den.

Viser hvor meget hukkommelse forskellige variabeltyper bruger. Det er afhængigt af dit OS.
*/

#include <stdio.h>

int linje;

main()
{
	printf("\n Variabel	Størrelse i bytes\n ");
	for (linje=0; linje<33; linje++)
		printf("-");
	printf("\n char			%d", sizeof(char));
	printf("\n int			%d", sizeof(int));
	printf("\n short			%d", sizeof(short));
	printf("\n long			%d", sizeof(long));
	printf("\n unsigned char		%d", sizeof(unsigned char));
	printf("\n unsigned int		%d", sizeof(unsigned int));
	printf("\n unsigned short		%d", sizeof(unsigned short));
	printf("\n unsigned long		%d", sizeof(unsigned long));
	printf("\n float			%d", sizeof(float));
	printf("\n double			%d", sizeof(double));
	printf("\n\n");

	return 0;
}

