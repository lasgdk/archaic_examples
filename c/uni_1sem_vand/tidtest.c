#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
  struct timeval tv;

  time_t curtime;
  int i;
  for(i=0; i<3; i++){
    gettimeofday(&tv, NULL); 
    curtime=tv.tv_sec;

    printf("%ld ",(long)curtime);
//printf("%d ",tv.tv_usec);
    sleep(1);

  }
//  strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
//  printf("%s%ld\n",buffer,tv.tv_usec);

  return 0;
}
