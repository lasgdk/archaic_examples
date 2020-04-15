/*
   Code by Lars Sommer, <lasg@lasg.dk>
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program. 
*/

#include <stdio.h>

void resetboard();
void compplay();
void userplay();
void showboard();
int checkfull();
int checkwin();
int board[3][3];

int main(void)
{
	int actualplayer;

	srand((unsigned int) time(NULL));

	printf("\n\nDu har startet \n\n");
	printf("   * * * * * * *\n");
	printf("  * 3-på-stribe! *\n");
	printf("   * * * * * * *\n\n\n");

	actualplayer=rand()%2;
	if( actualplayer == 0 )
	{
		printf("Computeren starter spillet...\n");
	}
	else
	{
		printf("Du starter!\n");
	}

	resetboard();
	
	while( (checkwin() == 0) && (checkfull() == 0) )
	{
		if( actualplayer==0 )
		{
			compplay();
			actualplayer=1;
		}
		else
		{
			userplay();
			actualplayer=0;
		}
		showboard();
	}

	showboard();
	if( checkwin() == -3 )
	{
		printf("Du vandt!");
	}
	else if( checkwin() == 3 )
	{
		printf("Desværre du, computeren vandt..");
	}
	else if( checkfull() == 1)
	{
		printf("Brættet er fyldt. Ingen vinder.. Prøv igen.");
	}

	printf("\n\n");

	return 0;
}


void resetboard()
{
	int i,j;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			board[i][j]=0;
		}
	}
}


void compplay()
{
	int x=1,y=1;
	printf("Computerens tur:\n");
	while (board[x][y] != 0)
	{
		x=rand()%3;
		y=rand()%3;
	}
	board[x][y]=1;
}


void userplay()
{
	int check=0,c=0,x,y;
	while( check==0 )
	{
		printf("Din tur\n");
		printf("Indtast hvor du vil sætte kryds,\n ved at indtaste et tal mellem 1 og 9.\n");
		while( c<1 || c>9 )
		{
			scanf("%d",&c);
		}

		x=(c-1)/3;
		y=(c-1)%3;

		if( board[x][y] == 0)
		{
			check=1;
			board[x][y]=-1;
		}
		else
		{
			printf("Det felt er jo allerede optaget..\n");
			c=0;
		}
	}
}


void showboard()
{
	int i,j;
	printf("\n");
	printf("-------------\n");
	for(i=0;i<=2;i++)
	{
		printf("|");
		for(j=0;j<=2;j++)
		{
			if( board[i][j] == -1 )
			{
				printf(" X |");	
			}
			else if( board[i][j] == 1 )
			{
				printf(" O |");
			}
			else
			{
				printf("   |");
			}
		}
		printf("\n");
		printf("-------------");
		printf("\n");
	}
	printf("\n");
}


int checkfull()
{
	int i,j;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if( board[i][j] == 0 )
			{
				return 0;
			}
		}
	}
	return 1;
}


int checkwin()
{
	int i,j,res=0;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			res=res+board[i][j];
			if( (res == 3) || (res == -3) )
			{
				return res;
			}
		}
		res=0;

		for(j=0;j<=2;j++)
		{
			res=res+board[j][i];
			if( (res == 3) || (res == -3) )
			{
				return res;
			}
		}
		res=0;
	}
	return 0;
}




