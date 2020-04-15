#include <math.h>

#define SWAP(a,b) tempr=(a); (a)=(b); (b)=tempr

void fft(double*, int,int);

int main(int argc, char** argv){
	int i=1;
	double *d;
	if( (argc%2) ==0 )
	{
		printf("Wrong number of inputs. Must be even!\n");
		exit(1);
	}
	d = (double*)malloc(argc);

	for(i=1;i<argc;i++)
	{
		d[i]=atof(argv[i]);
		printf("%d",atoi(argv[i]));
		printf("%d ",d[i]);
	}



//	double d[8]={0,0,1,0,0,0,0,0};
	int n=4;
	fft(d,n,i);

	for(i=0;i<10;i++)
	{
		printf("%f ",d[i]);
		if( (i%2)==1 )
			printf("\n");
	}


	free(d);
	return 0;
}


void fft(double *data,int nn,int isign) {
   int n,mmax,m,j,istep,i;
   double wtemp,wr,wpr,wpi,wi,theta,tempr,tempi;
   n=nn<<1;
   j=1;
   for (i=1; i<n; i+=2) {
      if (j>i) {
         SWAP(data[j],data[i]);
         SWAP(data[j+1],data[i+1]);
      }
      m=n>>1;
      while (m>=2&&j>m) {
         j-=m;
         m>>=1;
      }
      j+=m;
   }
   mmax=2;
   while (n>mmax) {
      istep=2*mmax;
      theta=6.28318530717959/(isign*mmax);
      wtemp=sin(0.5*theta);
      wpr=-2.0*wtemp*wtemp;
      wpi=sin(theta);
      wr=1.0;
      wi=0.0;
      for (m=1; m<mmax; m+=2) {
         for (i=m; i<=n; i+=istep) {
            j=i+mmax;
            tempr=wr*data[j]-wi*data[j+1];
            tempi=wr*data[j+1]+wi*data[j];
            data[j]=data[i]-tempr;
            data[j+1]=data[i+1]-tempi;
            data[i]+=tempr;
            data[i+1]+=tempi;
         }
         wr=(wtemp=wr)*wpr-wi*wpi+wr;
         wi=wi*wpr+wtemp*wpi+wi;
      }
      mmax=istep;
   }

}


