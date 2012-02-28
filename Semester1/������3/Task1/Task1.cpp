#include <stdafx.h>
#include "psort.h"

int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0;
	fscanf(f, "%i", &n);
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%i", &a[i]);
	}
	fclose(f);

	pSort(a, n);

	int maxRepTwice = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == a[i - 1])
		{
			maxRepTwice = a[i];
			break;
		}
	}
	delete[] a;
	
	f = fopen("output.txt", "w");
	fprintf(f, "%i", maxRepTwice);
	
	fclose(f);
	return 0;
}