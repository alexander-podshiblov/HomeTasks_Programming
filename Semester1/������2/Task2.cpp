#include <stdafx.h>
#include <stdlib.h>

int main()
{
	printf("Enter the value of a and n, will be calculated a^n. \n a = ");
	int a = 0;
	scanf("%i", &a);
	printf("\n n = ");
	int n = 0;
	scanf("%i", &n);
	
	int residue = 0;
	int quotientN = n;
	long degreesA = a;
	long result = 1;

	while (quotientN >= 1)
	{
		if (quotientN == 1)
		{
			result = result * degreesA;
			quotientN = 0;
		}
		else
		{
			residue = quotientN % 2;
			quotientN = quotientN / 2;
			if (residue == 1)
				result = result * degreesA;
			degreesA = degreesA * degreesA;
		}
	}
	

	printf("a^n = %ld \n", result);

	system("PAUSE");
	return 0;
}