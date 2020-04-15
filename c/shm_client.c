#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

main(){
	int shmid;
	key_t key;
	char *shmstr, *str;

	key=1234;

	shmid=shmget(key,10,0666);
	if( shmid==-1 )
	{
		printf("ERROR: shmget\n");
		exit(1);
	}

	shmstr=shmat(shmid,0,0);
	if( shmstr==(char*)-1 )
	{
		printf("ERROR: shmat\n");
		exit(1);
	}
	printf("%c,%c,%c\n",shmstr[0],shmstr[1],shmstr[2]);

	shmstr[0]='2';

	return 0;
}


