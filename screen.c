#include "screen.h"
#include <stdio.h>

void setFGcolor(int fg)
{
	printf("\033[%d;1m", fg);
	fflush(stdout);
}

void resetColors(void)
{
	printf("\033[0m");
	fflush(stdout);
}

void gotoXY(int row, int col)
{
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

void clearScreen(void)
{
	printf("\033[2J");
	fflush(stdout);
}

void displayBar(double rms, int col)
{
	int i;
	for(i=70;i>=70-rms/100 && i>=2;i--)
	{
		//if(i<2) break;
		gotoXY(i, col);//start appear from the second row and go down
#ifndef UNICODE
		printf("*");
#else
		printf("%s", BAR);
#endif
	}
	fflush(stdout);
}
