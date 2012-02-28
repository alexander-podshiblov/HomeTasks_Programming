#include "stdafx.h"
#include "hash.h"
#include <string.h>

bool symbol(char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))
		return true;
	else
		return false;
}

void scanWord(char *s, FILE *f)
{
	fscanf(f, "%s", s);
	int n = strlen(s);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (symbol(s[i]))
		{
			k = i;
			break;
		}
		else if (i == n - 1)
			k = n - 1;
	}
	if (k > 0)
	{
		for (int i = 0; i < n - k; i++)
			s[i] = s[i + k];
		s[n - k] = '\0';
	}
	n = n - k;
	for (int i = n - 1; i >= 0; i--)
	{
		if (symbol(s[i]))
		{
			s[i + 1] = '\0';
			n = i + 1;
			break;
		}
		else if (i == 0)
			{
				s[0] = '\0';
				n = 0;
			}
	}
	for (int i = 0; i < n; i++)
		{
			if ((s[i] >= 'A') && (s[i] <= 'Z'))
				s[i] = s[i] + 32;
		}
	
}

int main()
{
	const int lengthArray = 30000;
	Word **m = createArray(lengthArray);

	FILE *f = fopen("input.txt", "r");
	
	while (!feof(f))
	{
		char s[50];
		scanWord(s, f);
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
	fclose(f);
	
	for (int i = 0; i < lengthArray; i++)
	{
		if (m[i] != NULL)
		{
			Word *tmp = m[i];
			while (tmp != NULL)
			{
				printf("%s  -  %i\n", tmp->s, tmp->repeats);
				tmp = tmp->next;
			}
		}
	}

	clear(m, lengthArray);
	delete[] m;
	scanf("%*");
	return 0;
}