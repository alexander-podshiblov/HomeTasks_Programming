#include <stdafx.h>
#include <string.h>


void scanWord(FILE *f, char *s)
{
	fscanf(f, "%s30", s);
}

bool repeat(char ch, char *s2)
{ 
	int n = strlen(s2);
	bool repeat = false;
	for (int i = 0; i < n; i++)
		if (ch == s2[i])
			repeat = true;
	return repeat;
}

void addToStr(char ch, char *s2)
{
	int n = strlen(s2);
	s2[n] = ch;
	s2[n + 1] = '\0';
}

void printModWord(char *s)
{
	int n = strlen(s);
	char s2[30];
	s2[0] = '\0';
	for (int i = 0; i < n; i++)
	{
		if (!repeat(s[i], s2))
		{
			printf("%c", s[i]);
			addToStr(s[i], s2);
		}
	}
	printf(" ");
}

int main()
{
	FILE *f = fopen("input.txt", "r");
	char s[150];

	while (!feof(f))
	{
		scanWord(f, s);
		printModWord(s);
	}



	scanf("%*s");
	return 0;
}