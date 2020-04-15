#include <stdio.h>

void printdice();
void cleardice();
void throwdice();

char dots[7];

int main(void)
{

	srand((unsigned int)(time(NULL)));


	cleardice();
	throwdice();
	printdice();
	

	return 0;
}

void throwdice()
{
	int d=0;
	d = (rand()%6)+1;
	switch (d){
		case 1:
			dots[3]='.';
			break;
		case 2:
			dots[0]='.';
			dots[6]='.';
			break;
		case 3:
			dots[0]='.';
			dots[3]='.';
			dots[6]='.';
			break;
		case 4:
			dots[0]='.';
			dots[1]='.';
			dots[5]='.';
			dots[6]='.';
			break;
		case 5:
			dots[0]='.';
			dots[1]='.';
			dots[3]='.';
			dots[5]='.';
			dots[6]='.';
			break;
		case 6:
			dots[0]='.';
			dots[1]='.';
			dots[2]='.';
			dots[4]='.';
			dots[5]='.';
			dots[6]='.';
	}
}


void cleardice()
{
	int i;
	for(i=0;i<=7;i++)
	{
		dots[i]=' ';
	}
}


void printdice()
{
	printf("\n   _____\n");
	printf("  | %c %c |\n",dots[0],dots[1]);
	printf("  | %c%c%c |\n",dots[2],dots[3],dots[4]);
	printf("  | %c %c |\n",dots[5],dots[6]);
	printf("  |_____|\n\n");
}


