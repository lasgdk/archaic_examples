#include <stdio.h>

/*
 *Eksempel der viser "Call by value" og "Call by reference" begreberne.
 *Lars Sommer, lasg@lasg.dk, 270307
 * */

int add(int, int);	//Denne funktion bruger "Call by value"
void swap(int*,int*);	//Denne bruger "Call by reference"

int main(){
	int a=3;
	int b=5;
	int res;

	res=add(a,b);	//Kaldt med "Call by value", da værdierne 3 og 5 
			// sendes direkte til funktionen.
			
	printf("a=%d, b=%d, a+b=%d\n",a,b,res);

	swap(&a,&b);	//Kaldt med "Call by reference", da kun referencer
			// (adresserne) til a og b sendes til funktionen.
			
	printf("a=%d, b=%d\n",a,b);
	return 0;
}

int add(int c, int d){
	return c+d;
}

void swap(int *e,int *f){
	int buf;
	buf=*e;
	*e=*f;
	*f=buf;
}
