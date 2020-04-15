#include <stdio.h>
#include <stdlib.h>

int spillervalg(void);
int computervalg(void);

int main(void)
{
	int b,c,res;
	char *ting[]={"sten","papir","saks"};
	char *vinder[]={"det blev uafgjort..","du har vundet!","computeren vandt"};
	srand((unsigned int)time(NULL));

	b=spillervalg();
	c=computervalg();

	printf("Du valgte %s\n",ting[b]);
	printf("Computeren valgte %s\n",ting[c]);

	res=b-c;

	switch (res){
		case -2:
			res=1;
			break;
		case -1:
			res=2;
			break;
		default:
			break;
	}

	printf("Det vil sige %s\n",vinder[res]);

	return 0;
}

int spillervalg(void)
{
	int a=0;

	while( a!=1 && a!=2 && a!=3 )
	{
	printf("1 = Sten\n2 = Papir\n3 = Saks\n");
	printf("Vælg sten, papir eller saks ved at skrive et af tallene 1, 2, 3:\n");
	scanf("%d",&a);
	}

	return (a-1);
}

int computervalg(void)
{
	int a;
	a=rand()%3;
	return a;
}


