#include <curses.h>
#include <stdio.h>

int main(void)
{
	char c;
	char *str;
	int i=0;

	WINDOW *wnd;
	wnd=initscr();

	cbreak();
	noecho();

	str=malloc(32*sizeof(char));

	while (c!= '\n')
	{
		c=getch();
		if (c == '\n')
			break;
		str[i++]=c;
	}
	endwin();

	printf("%s",str);
		return 0;
}

