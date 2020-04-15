/*
 *# Two threads are sharing data (4 ints) protected by a semaphore construct
    1. Write the skeleton code get_var(int var_number, int &pvar)
       2. Write the skeleton code put_var(int var_number, int &pvar)
          3. Remember lock mechanism
	     4. Explain real time problems due to lock
	        5. Introduce "trywait" and modify skeleton code to illustrate that (hint return value == result of operation) 
 * */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 64
#define NUM_VARS 8
#define MAX_NUM 512

pthread_t thread[NUM_THREADS];
sem_t sem[NUM_VARS];
int ints[NUM_VARS];

int get_var(int var_number, int pvar){
	if( sem_trywait(&sem[pvar]) == 0 )
	{
		printf("Int %d is set to %d\n",pvar,ints[pvar]);
		sem_post(&sem[pvar]);
	}
	else
	       return 1;	
}

int set_var(int var_number, int pvar){
	if( sem_trywait(&sem[pvar]) == 0 )
	{
		printf("Sætter %d til %d\n",pvar,var_number);
		ints[pvar] = var_number;
		sem_post(&sem[pvar]);
	}
	else
	       return 1;	
}

void *gsv_thread(void *startval){
	int j,i,pvar,var_number,type,ret;
	i=(int)startval;

	for(j=0;j<i+1;j++)
	{
		pvar = rand()%NUM_VARS;
		var_number = rand()%MAX_NUM;
		type = rand()%3;
	
		if( type == 0)
			ret = set_var(var_number,pvar);
		else
			ret = get_var(var_number,pvar);

		if( ret!=0 )
		{
//			printf("Tråd %d må ikke lave noget lige nu\n",i);
		}
		sleep(1);
	}
}

int main(int argc, char *argv[]){
	int i,t;
	int ret=0;

	for(i=0;i<NUM_VARS;i++)
	{
		ints[i]=0;
	}

	srand((unsigned int) time(NULL));

	for(i=0;i<NUM_VARS;i++)
	{
		sem_init(&sem[i],0,1);
	}


	for(t=0;t<NUM_THREADS;t++)
	{
		printf("Opretter tråd %d\n",t);
		ret = pthread_create(&thread[t],NULL,gsv_thread,(void *)t);
		if( ret )
		{
			printf("Fejl ved oprettelse af tråd\n");
			exit(1);
		}
		sleep(1);
	}

	for(i=0;i<NUM_VARS;i++)
	{
		sem_destroy(&sem[i]);
	}

	pthread_exit(NULL);
	return 0;
}

