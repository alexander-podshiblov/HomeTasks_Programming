#include <stdafx.h>
#include <stdlib.h>

__int64 factorial(int n)
{
	if (n == 1)
		return 1;
	else 
		return (n * factorial(n - 1));
}

int main()
{
	printf("Enter N, will be calculated N! \n N = ");
	int n = 0;
	scanf("%i", &n);

	printf("\n How to find: recursive or iterative (r / i) ? ");
	char choice;
	scanf("%s", &choice);
	

	if (choice == 'r')
	{
		__int64 fac = factorial(n);
		printf("\n N! = %I64d \n", fac);
	}
	
	if (choice == 'i')
	{
		__int64 fac = 1;
		for (int i = 1; i <= n; i++)
			fac = fac * i;
		printf("\n N! = %I64d \n", fac);
	}

	system("PAUSE");
	return 0;
}