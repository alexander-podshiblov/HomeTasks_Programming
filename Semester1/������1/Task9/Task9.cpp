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

	long degreeA = a;
	for (int i = 1; i < n; i++)
	{
		degreeA = degreeA * a;
	}	
	
	printf("\n a^n = %ld \n\n", degreeA);
	
	system("PAUSE");
	return 0;
}