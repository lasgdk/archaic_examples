#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS	4

void *hello(void *ptid){
	printf("Hej verden fra traad nr %d!\n",ptid);
	pthread_exit(NULL);
}

int main(void){
	pthread_t pthreads[NUM_THREADS];
	int rc,t;
	for (t=0; t<NUM_THREADS;t++){
		printf("Opretter traad nr %d\n",t);
		rc=pthread_create(&pthreads[t],NULL,hello,(void *)t);
		if (rc){
			printf("Fejl %d fra pthread_create!\n",rc);
			exit(1);
		}
	}
	pthread_exit(NULL);
}

