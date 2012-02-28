#include <stdafx.h>
#include <stdlib.h>

int main(void)
{
	int a = 0;
	int b = 0;
	printf("Enter the value of x, will be calculated partial quotient of a/b. \n a=");
	scanf("%i", &a);
	printf("\n b="); 
	scanf("%i", &b);
	
	int k = 0;
	while (a >= b)
	{
		a = a - b;
		k++;
	}
	
	printf("\n Integral part of the division of a/b = %i \n", k);

	system("PAUSE");
	
	return 0;
}