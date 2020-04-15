#include <stdio.h>
//#include <string.h>

struct values {
	char name[16];
	int age;
	int number;
}

void setbuildin(void);

int main(int argc,char**argv){

	char *filename="example.conf";
	FILE *fp;

	setbuildin();

	If arguements are given, use these
	if(argv[1]=="-c" && 2<argc){
		filename=argv[2];
		printf("You changed the config file path to %s\n",filename);
	}
	else{
		printf("Using default config file %s.\n",filename);
		printf("To change this, run with \"-c <filename>\"\n");
	}

	//Open file, or use default buildin values, if any problems with file.
	if( (fp=fopen(filename,"r"))==NULL )
	{
		fprintf(stderr,"Cannot access file %s. Using build in values\n",filename);
	}

	//Read lines in from file.
	//scan for options
	//set values

	fclose(fp);
	return 0;
}

//If config file gives some problems, or are missing some of the options,
// use these instead
void setbuildin(void)
{
	values.name="Testing";
	values.age=42;
	values.number=17;
}


