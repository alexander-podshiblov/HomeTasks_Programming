#include <stdafx.h>

int swap(int *x, int i, int j)
{
	int k = x[i];
	x[i] = x[j];
	x[j] = k;
	return 0;
}

int main(void)
{
	int n = 0;
	int m = 0;
	int x[100];
	FILE *f = fopen("input.txt", "r");
	fscanf(f, "%i%i", &n, &m);
	for (int i = 0; i < n+m; i++)
	{
		fscanf(f, "%i", &x[i]);
	}
	fclose(f);

	int k = 0;
	for (int i = 0; i <= (n + m - 1) / 2; i++)
	{
		swap(x, i, n + m - i - 1);
	}

	for (int i = 0; i <= (m - 1) / 2; i++)
	{
		swap(x, i, m - i - 1);
	}
	
	for (int i = 0; i <= (n - 1) / 2; i++)
	{
		swap(x, i + m, n - i - 1 + m);
	}

	fclose(f);

	f = fopen("output.txt", "w");
	for (int i = 0; i < n + m; i++)
	{
		fprintf(f, "%i ", x[i]);
	}
		
	return 0;
}