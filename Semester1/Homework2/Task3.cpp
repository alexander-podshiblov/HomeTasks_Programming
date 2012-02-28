#include <stdafx.h>
#include <stdlib.h>

int elements(int *a)
{
	int n = 0;
	for (int i = 0; a[i] != 0; i++)
		n++;
	return n;
}

int partition(int *a, int c, int n)
{
	int sum = 0;
	for (int i = c; i < n; i++)
		sum = sum + a[i];
	for (int i = c; sum != 0; i++)
	{
		a[i] = 1;
		sum--;
	}
	
	return 0;
}

int main()
{
	int n;
	printf("Enter the value of N will be printed representation of all positive integer N, the sum of positive terms.\n\nn = ");
	scanf("%i", &n);
	printf("\n\n");
	
	for (int i = 0; i < n - 1; i++)
		printf("1 + ");
	printf("1\n");

	int a[100];
	for (int i = 0; i < n; i++)
		a[i] = 1;

	int k = 0;
	int c = 0;


	while (n > 1)
	{
		a[n - 1]--;
		a[n - 2]++;
		c = n - 1;
		for (int i = n - 2; a[i] > a[i - 1] && i > 0; i--)
		{
			k = a[i];
			a[i] = a[i - 1];
			a[i - 1] = k;
			c = i;
		}
		n = elements(a);
		partition(a, c, n);
		n = elements(a);

		for (int i = 0; i < n - 1; i++)
		{
			printf("%i + ", a[i]);
		}
		printf("%i\n", a[n - 1]);
	}
	
	printf("\n");
	
	system("PAUSE");
	return 0;
}