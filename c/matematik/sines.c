#include <stdio.h>
#include <math.h>

int main(){
	int	ang_deg;
	double	ang_rad, pi, sinv, cosv, tanv;

	printf("\nComputed sin,cos,tan function table\n\n");

	//pi = 4.0 * atan(1.0);
	pi = M_PI;
	printf("The value of PI is approxed to: %f \n\n",pi);

	printf("Angle\tSine\t\tCosine\t\tTangens\n");
	printf("-----\t----\t\t------\t\t-------\n");

	ang_deg=0;

	while ( ang_deg <= 360 ){
		ang_rad = pi * ang_deg / 180.0;
		sinv = sin(ang_rad);
		cosv = cos(ang_rad);
		tanv = tan(ang_rad);
		printf("%3d\t%f\t%f\t%f\n",ang_deg,sinv,cosv,tanv);

		ang_deg = ang_deg + 10;
	}
}
