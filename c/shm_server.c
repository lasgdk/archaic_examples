#include <machine/param.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main(){
	int shmid;
	key_t shmkey=1234;
	char *str,*shmstr;

	shmid = shmget(shmkey,10,IPC_CREAT|0666);
	if( shmid==-1 )
	{
		exit(1);
	}

	shmstr = shmat(shmid,0,0);
	if( shmstr==(char*)-1 )
	{
		exit(1);
	}

	shmstr[0]='1';
	shmstr[1]='3';
	shmstr[2]='4';

	while( shmstr[0]!='2' )
	{
		printf("%c\n",shmstr[0]);
		sleep(1);
	}


	return 0;
}
