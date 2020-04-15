#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS	1000
#define TIMES	10000000

int glob=0;
pthread_mutex_t mutexsum;


void *calc(void *ptid){
	int i=0;
	pthread_mutex_lock (&mutexsum);
	for(i=0;i<TIMES;i++)
	{
		if (((int)ptid%2)==0)
			glob++;
		else
			glob--;
	}
	pthread_mutex_unlock (&mutexsum);

	printf("Thread %d har sat glob til %d!\n",ptid,glob);

//	pthread_exit(NULL);
}

int main(void){
	pthread_t pthreads[NUM_THREADS];
	int rc,t;
	   pthread_mutex_init(&mutexsum, NULL);
	for (t=0; t<NUM_THREADS;t++){
		printf("Opretter traad nr %d\n",t);
		rc=pthread_create(&pthreads[t],NULL,calc,(void *)t);
		if (rc){
			printf("Fejl %d fra pthread_create!\n",rc);
			exit(1);
		}
	}
	 pthread_mutex_destroy(&mutexsum);
	pthread_exit(NULL);
	printf("Glob er nu %d\n",glob);
}

