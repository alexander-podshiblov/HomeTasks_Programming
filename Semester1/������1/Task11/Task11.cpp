#include <stdafx.h>

int qSort(int *m, int n)
{
	int i = 0;
	int j = n - 1;
	int exchange;
	int p = m[n / 2]; //reference item

	while (i <= j)
	{
		while (m[i] < p)
		{
			i++;
		}
		while (m[j] > p)
		{
			j--;
		}
			
		if (i <= j)
		{
			exchange = m[i];
			m[i] = m[j];
			m[j] = exchange;
			i++;
			j--;
		}
	}
	
	if (j > 0)                    //if left subarray contains more than one item
			qSort(m, j + 1);
	if (i < n - 1)					  //if right subarray contains more than one item
			qSort(m + i, n - i);

return 0;
}
	
int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0;
	fscanf(f, "%i", &n);
	int m[500];
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%i", &m[i]);
	}
	fclose(f);

	qSort(m, n);

	f = fopen("output.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%i ", m[i]);
	}
	fclose(f);

	return 0;
}