#include <stdio.h>
#include <math.h>

#define TURNS 9

int main(){
	int	ang_deg,i;
	double	ang_rad, pi, sinv ;


	//pi = 4.0 * atan(1.0);
	pi = M_PI;

	printf("\n\n");
	printf("---------------1-----------------------0-----------------------1---\n");

	for(ang_deg=0;ang_deg<=360*TURNS;ang_deg+=10)
	{

		ang_rad = pi * ang_deg / 180.0;
		sinv = sin(ang_rad)*25 +30;

		printf("%f",(sinv-30)/25);

		for(i=0;i<=(int)sinv;i++)
		{
			printf(" ");
		}
		printf(".");

		printf("\n");
		usleep(10000);
	}
	return 0;
}
