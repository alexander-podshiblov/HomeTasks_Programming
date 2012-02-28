#include <stdafx.h>

int twoToTen (int *a, int n)
{
	int k =1;
	int result = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == 1)
			result = result + k;
		k = k * 2;
	}
	return result;
}

int *tenToTwo (int k)
{
	int n = 0;
	int *m = new int[11];
	
	for(int i = 0; i < 11; i++)
		m[i] = 0;

	if (k != 0)
	{
		while (k > 1)
		{
			m[10 - n] = k % 2;
			k = k / 2;
			n++;
		}
	m[10 - n] = 1;
	}
	
	return m;
}

double mantToTen (int *a)
{
	long long degreeOfTwo = 2;
	double result = 0;
	for (int i = 0; i < 52; i++)
	{
		result = result + a[i] * (1.0 / degreeOfTwo);
		degreeOfTwo = degreeOfTwo * 2;
	}
	result = result + 1;
	return result;
}

int main()
{
	printf("Enter a number, it will be displayed in exponential form: \n");
	double d = 0.0;
	scanf("%lf", &d);
	printf("\n");
	
	int bitForm[64] = {0};
	unsigned char *c = (unsigned char *)(&d);
	
	unsigned char x[8];
	
	for (int i = 0; i < 8; i++)
	{
		x[i] = *(c + i);
	}

	int degreeOfTwo = 1;
	
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (x[j] & degreeOfTwo)
				bitForm[63 - j * 8 - i] = 1;
			degreeOfTwo = degreeOfTwo * 2;
		}
		degreeOfTwo = 1;
	}

	int lengthExp = 11;
	int lengthMant = 52;
	
	int expTen = twoToTen(bitForm + 1, lengthExp);
	expTen = expTen - 1023;
	int *expTwo = tenToTwo(expTen);
	
	if (bitForm[0] == 1)
		printf("- ");
	printf("1.");
	for (int i = 12; i < 12 + lengthMant; i++)
		printf("%i", bitForm[i]);
	printf(" * 2^");
	for (int i = 0; i < lengthExp; i++)
		printf("%i", expTwo[i]);

	printf("\n\n");
	
	if (bitForm[0] == 1)
		printf("- ");
	printf("%lf", mantToTen(bitForm + 12));
	printf(" * 2^%i", expTen);
	

	scanf("%*s");
	return 0;
}