#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS	1000
#define TIMES	10000000

int glob=0;

void *calc(void *ptid){
	int i=0;
	for(i=0;i<TIMES;i++)
	{
		if (((int)ptid%2)==0)
			glob++;
		else
			glob--;
	}

	printf("Thread %d har sat glob til %d!\n",ptid,glob);

//	pthread_exit(NULL);
}

int main(void){
	pthread_t pthreads[NUM_THREADS];
	int rc,t;
	for (t=0; t<NUM_THREADS;t++){
		printf("Opretter traad nr %d\n",t);
		rc=pthread_create(&pthreads[t],NULL,calc,(void *)t);
		if (rc){
			printf("Fejl %d fra pthread_create!\n",rc);
			exit(1);
		}
	}
	pthread_exit(NULL);
	printf("Glob er nu %d\n",glob);
}

