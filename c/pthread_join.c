#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS	42

void *busywork(void *null){
	int i;
	double res=0.0;
	for(i=0;i<=10000000;i++)
	{
		res=res+(double)random();
	}
	printf("Result is %e\n",res);
	pthread_exit((void *) 0);
}

int main(void){
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	int rc,t,status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	for(t=0;t<NUM_THREADS;t++)
	{
		printf("Opretter thread %d\n",t);
		rc=pthread_create(&thread[t],&attr,busywork,NULL);
		if( rc )
			exit(1);
	}

	pthread_attr_destroy(&attr);
	for(t=0;t<NUM_THREADS;t++)
	{
		rc=pthread_join(thread[t],(void **)&status);
		if( rc )
			exit(1);
		printf("Komplet join med thread %d med status %d\n",t,status);
	}
	pthread_exit(NULL);
}

