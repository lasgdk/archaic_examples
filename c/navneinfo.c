#include <stdio.h>
#include <string.h>

char buffer[256], *p_buffer;
int cur;

main()
{
	printf("Skriv dit fulde navn og tryk <Enter>: \n");
	gets(buffer);
	p_buffer = buffer;
	printf("Dit fornavn er ");

	for ( cur = 0; cur < strlen(buffer); cur++ ){
		if(buffer[cur] == 32){
			cur = strlen(buffer);
			}
		printf("%c",buffer[cur]);
		}
	printf(", og dit fulde navn er %s", p_buffer);
	printf(", som indeholder %d tegn!\n", strlen(buffer));

	return 0;
}

