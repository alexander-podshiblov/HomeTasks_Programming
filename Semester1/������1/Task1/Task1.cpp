#include <stdafx.h>
#include <stdlib.h>

int main(void)
{
	int x = 0;
	printf("Enter the value of x, will be calculated x^4+x^3+x^2+x+1. \n x=");
	scanf("%i", &x); 

	int squareX = x * x;

	int result = (squareX + x) * (squareX + 1) + 1;

	printf("\n x^4+x^3+x^2+x+1=%i \n\n", result);
	
	system("PAUSE");
	
	return 0;
}