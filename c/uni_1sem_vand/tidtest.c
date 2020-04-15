#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  char buffer[30];
  struct timeval tv;

  time_t curtime;
while(buffer !=3){
  gettimeofday(&tv, NULL); 
  curtime=tv.tv_sec;

printf("%d ",curtime);
//printf("%d ",tv.tv_usec);
sleep(1);

}
//  strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
//  printf("%s%ld\n",buffer,tv.tv_usec);

  return 0;
}
