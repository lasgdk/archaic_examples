#include <unistd.h>
#include <sys/types.h>

int i=0;

fparent(){
	int j;
	for(j=0;j<10;j++)
	{
		printf("P printing %d\n",i);
		sleep(1);
	}

}

fchild(){
	int j;
	for(j=0;j<10;j++)
	{
		i++;
		printf("C setting %d\n",i);
		sleep(1);
	}

}

int main(void){
	pid_t pid;

	pid=vfork();

	printf("%d\n",pid);

	if( pid<0 )
	{
		exit(1);
	}
	if( pid==0 )
	{
		fparent();
	}
	if( pid>0 )
	{
		fchild();
	}

	return 0;
}
