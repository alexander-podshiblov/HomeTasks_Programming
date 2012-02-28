#include <stdafx.h>

void printComment(FILE *f)
{
	char c = 0;
	while ((c != '\n') && (!feof(f)))
	{
		c = fgetc(f);
		printf("%c", c);
	}

}

int main()
{
	FILE *f = fopen("psort.cpp", "r");
	char c = 0;
	while (!feof(f))
	{
		c = fgetc(f);
		if (c == '"')
		{
			c = fgetc(f);
			while (c != '"')
			{
				c = fgetc(f);
			}
		}
		if (c == '/')
		{
			c = fgetc(f);
			if (c == '/')
			{
				printf("//");
				printComment(f);
			}
		}
	}
	fclose(f);


	scanf("%*s");
	return 0;
}