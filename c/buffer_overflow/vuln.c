#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int bof(char *string) {
  char buffer[4];
  strcpy(buffer, string);
  return 1;
}
 
int main(int argc, char *argv[]) {
  bof(argv[1]);
  printf("Done..\n");
  return 1;
}
