#include <stdio.h>
greet(char *tmp1,char *tmp2) {
	char navn[64];
	strcpy(navn, tmp2);
	printf("Hej %s %s\n", tmp1, navn);
}

main(int argc, char * argv[]){
	greet(argv[1], argv[2]);
	printf("Farvel %s %s\n", argv[1], argv[2]);
}
