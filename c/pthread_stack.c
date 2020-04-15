#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 4
#define N 1000
#define MEGAEXTRA 70

pthread_attr_t attr;

void *dowork(void *threadid){
	double A[N][N];
	int i,j;
	size_t min_stack_size;

	pthread_attr_getstacksize (&attr,&min_stack_size);
	printf("Thread nummer %d har en stack size på %d bytes\n",threadid,min_stack_size);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			A[i][j] = ((i*j)/3.456)+(N-i);
	pthread_exit(NULL);
}

int main(void){
	pthread_t threads[NUM_THREADS];
	size_t stacksize;
	int rc,t;

	pthread_attr_init(&attr);
	pthread_attr_getstacksize(&attr,&stacksize);
	printf("Normal stack size er %d bytes\n",stacksize);
	stacksize=sizeof(double)*N*N*MEGAEXTRA;
	printf("Det kræver %d bytes stack til hver tråd\n",stacksize);
	pthread_attr_setstacksize(&attr,stacksize);
	printf("Opretter threads med stack size på %d bytes\n",stacksize);
	
	for(t=0;t<NUM_THREADS;t++)
	{
		rc=pthread_create(&threads[t],&attr,dowork,(void*)t);
		if( rc )
			exit(1);
	}
	printf("Har oprettet %d threads nu\n",t);
	pthread_exit(NULL);
}

