#include <stdafx.h>
#include <stdlib.h>

int numberFib(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return (numberFib(n-1) + numberFib(n-2));
}

int main()
{
	int n = 0;
	printf("Enter the value of n, will be printed Fibonacci number n. \n n = ");
	scanf("%i", &n);

	printf("\n How to find: recursive or iterative (r / i) ? ");
	char choice;
	scanf("%s", &choice);

	
	if (choice == 'r')
	{
		int nf = numberFib(n);
		printf("\n %i \n", nf);	
	}
		
	if (choice == 'i')
	{
		int nf = 0;
		int c1 = 0;
		int c2 = 1;
		
		if (n == 1)
			nf = 0;
		else if (n == 2)
			nf = 1;
		else
			for (int i = 3; i <= n; i++)
			{
				nf = c1 + c2;
				c1 = c2;
				c2 = nf;
			}
		printf("\n %i \n", nf);
	}




	system("PAUSE");
	return 0;
}