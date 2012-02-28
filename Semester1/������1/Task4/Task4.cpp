#include <stdafx.h>
#include <stdlib.h>

int sumDigits(int a)
{
	int sum = 0;
	if (a <= 9)
	{
		sum = a;
	}

	else if ((a >= 10) && (a <= 99))
	{
		sum = a / 10 + a % 10;
	}

	else
	{
		sum = a / 100 + (a % 100) / 10 + (a % 100) % 10;
	}
	
	return sum;
}

int main(void)
{
	int m[27];
	for (int i = 0; i < 27; i++)
	{
		m[i] = 0;
	}

	
	int num = 0;
	while (num <= 999)
	{
		m[sumDigits(num) - 1]++;
		num++;
	}
	
	int numWT = 0;
	for (int i = 0; i < 27; i++)
	{
		m[i] = m[i] * m[i];
		numWT = numWT + m[i];
	}

	printf("The number of winning ticket - %i \n", numWT);
	
	system("PAUSE");
	return 0;
}