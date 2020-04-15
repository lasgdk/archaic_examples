#include <curses.h>
#include <stdio.h>

int main(void)
{
	char c;
	char str[33];
	int i=0;

	for(i=0;i<32;i++)
		str[i]='\0';

	WINDOW *wnd;
	wnd=initscr();

	cbreak();
	noecho();

	for(i=0;i<31;i++)
	{
		c=getch();
		if (c == '\n')
			break;
		str[i]=c;
	}
	endwin();

	printf("%s",str);
		return 0;
}

