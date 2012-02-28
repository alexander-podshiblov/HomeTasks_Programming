#include <stdafx.h>
#include <stdlib.h>

int insertMed(int *numerators, int *denominators, int  n, int k)
{
	for (int i = n; i > k; i--)
	{
		numerators[i] = numerators[i-1];
		denominators[i] = denominators[i-1];
	}
	numerators[k] = numerators[k-1] + numerators[k+1];
	denominators[k] = denominators[k-1] + denominators[k+1];
	
	return 0;
}

int main()
{
	printf("Enter N, will be printed in ascending order of all simple irreducible fractions included between 0 and 1 whose denominators do not exceed N \n N = ");
	int n = 0;
	scanf("%i", &n);
	printf("\n");
	
	int numerators[100]; //array of numerators
	int denominators[100]; //array of denominators
	
	numerators[0] = 0;
	denominators[0] = 1;
	numerators[1] = 1;
	denominators[1] = 1;
	int k = 2; //middleware n
	int numberFractions = 2; //elements in the array of fractions
	while (k <= n)
	{
		for (int i = 1; i < numberFractions; i++)
		{
			if (denominators[i] + denominators[i - 1] <= k)
			{
				insertMed(numerators, denominators, numberFractions, i); //Insert the median between (i - 1)-th and i-th fractions
				numberFractions++;
			}
		}
		k++;
	}
	
	printf("\n");
	
	for(int i = 0; i < numberFractions; i++)
	{
		printf("%i/%i ", numerators[i], denominators[i]);
	}

	printf("\n");

	system("PAUSE");
	return 0;
}