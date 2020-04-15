#include <stdio.h>

main(){
	int c=0,d=0;
	while(d<100){
		while(c<15){
			if(c<5){
				outp(c+c+2);
			} else {
				outp(0);
			}
			usleep(50000);
			c++;
		}
	c=0;
	d++;
	}

exit(0);
}

outp(int v){
	if(v != 0){
		printf("%d\n",v);
		sleep(1);
	}
}



