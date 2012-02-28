#include "stdafx.h"


int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0;
	int a[100];
	
	for (int i = 0; !feof(f); i++)
	{
		fscanf(f, "%i", &a[i]);
		n++;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			if (i == 0)
			{
				if (a[i] < 0)
					printf("- %i*x^%i ", -1 * a[i], n - 1 - i);
				else
					printf("%i*x^%i ", a[i], n - 1 - i);
			}
			else if	(i == n - 1)
			{
				if (a[i] < 0)
					printf("- %i", -1 * a[i]);
				else
					printf("+ %i", a[i]);
			}
			else if (i == n - 2)
			{
				if (a[i] < 0)
					printf("- %i*x", -1 * a[i]);
				else
					printf("+ %i*x ", a[i]);
			}
			else
			{
				if (a[i] < 0)
					printf("- %i*x^%i ", -1 * a[i], n - 1 - i);
				else
					printf("+ %i*x^%i ", a[i], n - 1 - i);
			}
		}
	}
	
	scanf("%*");
	return 0;
}

