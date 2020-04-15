/*
   Code by Lars Sommer, <lasg@lasg.dk>
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program.

   This is a simple example of an one-armed-bandit simulator.
   It uses functions, randomness and simple arithmetics.
*/

#include <stdio.h>
#include <stdlib.h>

int play(int cash);

int main(void)
{
	int cash=50;
	char valg;
	srand( (unsigned int) time( NULL ));

	printf("\nYou're now in a small casino in Las Vegas.\n");
	printf("Seated in front of a one armed bandit,\n");
	printf(" with 50$ in small coins\n\n");

	while(1)
	{
		printf("Your cash is %d$\n",cash);

		if( cash==0 )
		{
			printf("!! GAME OVER !!\n");
			break;
		}
		sleep(1);
		printf("Pull the lever or die like the rest? p or q: ");
		while( 1)
		{
			scanf("%c",&valg);
			if( valg=='q' ) 
			{
				printf("You ended up with %d$\n",cash);
				printf("Have a nice day...\n\n");
				return 0;
			}
		 	else if( valg=='p' ) 
			{
				cash=play(cash);
				break;
			}
		}
	}
	return 0;
}

int play(int cash)
{
	char* mulige[]={"BAR","BELL","PLUM","ORANGE","CHERRY","LEMON"};
	int a,b,c,price;
	cash--;

	a=rand()%5;
	b=rand()%5;
	c=rand()%5;

	printf("\nThe wheels are spinning....\n\n");
	sleep(1);
	//printf("[%s] [%s] [%s]\n\n",mulige[a],mulige[b],mulige[c]);
	printf("[%s] ",mulige[a]);
	//sleep(1);
	printf("[%s] ",mulige[b]);
	//sleep(1);
	printf("[%s] \n\n",mulige[c]);

	if( (a==0)&&(b==0)&&(c==0) ) price=250;
	else if( (a==1)&&(b==1)&&((c==0)||(c==1)) ) price=20;
	else if( (a==2)&&(b==2)&&((c==0)||(c==2)) ) price=14;
	else if( (a==3)&&(b==3)&&((c==0)||(c==3)) ) price=10;
	else if( (a==4)&&(b==4)&&(c==4) ) price=7;
	else if( (a==4)&&(b==4) ) price=5;
	else if( (a==4) ) price=2;
	else price=0;
	
	printf("You won %d$\n",price);
	cash=cash+price;

	return cash;
}

