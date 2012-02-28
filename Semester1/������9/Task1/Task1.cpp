#include "stdafx.h"
#include <string.h>
#include "hash.h"

void scanString(char *s, FILE *f)
{
	int i = 0;
	for (i = 0; i < 250; i++)
	{
		s[i] = fgetc(f);
		if ((s[i] == '\n') || (s[i] == EOF))
			break;
	}
	s[i] = '\0';
}

void scanText(FILE *f, const int lengthArray, Word **m)
{
	while (!feof(f))
	{
		char s[250];
		scanString(s, f);
		if (s[0] != '\0')
		{
			unsigned int a = hashFunc(s, lengthArray);
			if (m[a] == NULL)
				m[a] = createWord(s);
			else
			{
				Word *tmp = m[a];
				while ((tmp->next != NULL) && (strcmp(tmp->s, s) != 0))
				{
					tmp = tmp->next;
				}
				if (strcmp(tmp->s, s) == 0)
					tmp->repeats++;
				else
					tmp->next = createWord(s);
			}
		}
	}
}

int main()
{
	const int lengthArray = 300;
	Word **m = createArray(lengthArray);
	
	FILE *f = fopen("text1.txt", "r");
	scanText(f, lengthArray, m);
	fclose(f);
	
	f = fopen("text2.txt", "r");
	FILE *g = fopen("output.txt", "w");
	
	for (int i = 0; !feof(f); i++)
	{
		char s[250];
		scanString(s, f);
		unsigned int a = hashFunc(s, lengthArray);
		if (m[a] != NULL)
			fprintf(g, "%s\n", s);
	}
	fclose(f);
	fclose(g);
	
	clear(m, lengthArray);
	delete[] m;
	return 0;
}