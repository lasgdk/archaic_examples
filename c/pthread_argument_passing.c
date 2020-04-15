#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS	42

struct ptdata{
	int thread_id;
	int et_tal;
	char *en_tekst;
};
struct ptdata data_array[NUM_THREADS];

void *hello(void *ptarg){
	struct ptdata *egen_data;
	egen_data=(struct ptdata *) ptarg;
	printf("Hej verden fra traad nr %d!\n",egen_data->thread_id);
	printf("%s",egen_data->en_tekst);
	pthread_exit(NULL);
}

int main(void){
	pthread_t pthreads[NUM_THREADS];
	int rc,t;
	for (t=0; t<NUM_THREADS;t++){
		printf("Opretter traad nr %d\n",t);
		data_array[t].thread_id = t;
		data_array[t].et_tal = 42;
		data_array[t].en_tekst = "Hej verden!!\n";
		rc=pthread_create(&pthreads[t],NULL,hello,(void *)&data_array[t]);
		if (rc){
			printf("Fejl %d fra pthread_create!\n",rc);
			exit(1);
		}
	}
	pthread_exit(NULL);
}

