int countwords(char *saetning){
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
	char *saetning;
	saetning="Hej med dig";
	printf("der er %d ord\n",countwords(saetning));
	return 0;
}
