#include "stdafx.h"
#include <string.h>

int move(int s, char c, int (&a)[9][6])
{
	if ((c >= '0') && (c <= '9'))
		return a[s][0];
	else if (c == '.')
		return a[s][1];
	//else if (c == '*')
	//	return a[s][2];
	//else if (c == '^')
	//	return a[s][3];
	else if (c == '-')
		return a[s][4];
	else if (c == 'e')
		return a[s][5];
	else
		return -1;
}

bool finalState(int s)
{
	if (s == 1 || s == 3 || s == 5 || s == 7 || s == 9 || s == 6)
		return true;
	else
		return false;
}

bool doubl(char *&w)
{
	char *z = w;
	int const numState = 9;
	int const numSymbol = 6;
	int doubleMove[numState][numSymbol];
	FILE *f = fopen("doubleMove.txt", "r");
	for (int i = 0; i < numState; i++)
		for (int j = 0; j < numSymbol; j++)
			fscanf(f, "%i", &doubleMove[i][j]);
	fclose(f);
	
	////////////////////////////////////////////////////////

	int s = 0;
	int l = 0;
	while (*w != ' ' && *w != '\n' && *w != NULL)
	{
		s = move(s, *w, doubleMove);
		if (s == -1)
		{
			break;
		}
		w++;
		l++;
		
	}

	if (finalState(s))
		return true;
	else
	{
		s = 0;
		w = z;
		while (*w != ' ' && *w != '\n' && *w != NULL && w != z + l)
			{
				s = move(s, *w, doubleMove);
				if (s == -1)
				{
					break;
				}
				w++;
		
			}
	}
	if (finalState(s))
		return true;
	else
		return false;
}
