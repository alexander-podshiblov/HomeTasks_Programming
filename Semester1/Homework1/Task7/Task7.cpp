#include <stdafx.h>
#include <stdlib.h>

int main()
{
	printf("Enter N, will be printing the all prime numbers not exceeding N. \n N = ");
	int n = 0;
	scanf("%i", &n);
	
	int m[33000];
	for (int i = 0; i < n; i++)
	{
		m[i] = 1;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (j % i == 0)
				m[j] = 0;
		}	
	}

	for (int i = 2; i < n; i++)
	{
		if (m[i] == 1)
			printf("%i ", i);
	}
	printf("\n");

	system("PAUSE");
	return 0;
}