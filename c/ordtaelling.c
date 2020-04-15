char *saetning;

int countwords(){
	int actual=0;
	int words=1;
	while(saetning[actual] != '\0'){
		if (saetning[actual] == ' ')
			words++;
		actual++;
	}
	return words;
}

int main(){
	saetning="Hej med dig";
	printf("der er %d ord\n",countwords());
	return 0;
}
