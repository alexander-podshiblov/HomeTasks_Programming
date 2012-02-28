#include "stdafx.h"

int move(int s, char c, int (&a)[10][6])
{
	if ((c >= '0') && (c <= '9'))
		return a[s][0];
	else if (c == '.')
		return a[s][1];
	else if (c == '*')
		return a[s][2];
	else if (c == '^')
		return a[s][3];
	else if (c == '-')
		return a[s][4];
	else if (c == 'e')
		return a[s][5];
	else
		return -1;
}

char nextChar()
{
	char c = 0;
	scanf("%c", &c);
	return c;
}

bool finalState(int s)
{
	if (s == 1 || s == 3 || s == 5 || s == 7)
		return true;
	else
		return false;
}

int main()
{
	int const numState = 10;
	int const numSymbol = 6;
	int doubleMove[numState][numSymbol];
	FILE *f = fopen("doubleMove.txt", "r");
	for (int i = 0; i < numState; i++)
		for (int j = 0; j < numSymbol; j++)
			fscanf(f, "%i", &doubleMove[i][j]);
	fclose(f);
	
	////////////////////////////////////////////////////////

	char c = 0;
	int s = 0;
	c = nextChar();
	while (c != '\n')
	{
		s = move(s, c, doubleMove);
		if (s == -1)
		{
			break;
		}
		c = nextChar();
	}

	if (finalState(s))
		printf("YES\n");
	else
		printf("NO\n");


	scanf("%*");
	return 0;
}