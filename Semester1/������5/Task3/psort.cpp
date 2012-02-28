#include <stdafx.h>

int swap(int *a, int i, int j)
{
	int k = a[i];
	a[i] = a[j];
	a[j] = k;
	return 0;//fdgsdgagragarg
}

int screening(int *a, int i, int n)
{
	
	printf(" //test ");
	while (2 * i + 2 <= n)
	{
		if (2 * i + 2 < n)
		{
			if ((a[i] < a[2 * i + 1]) && (a[2 * i + 1] >= a[2 * i + 2]))
			{	
				swap(a, i, 2 * i + 1);//sklflfls ss fasefaw
				i = 2 * i + 1;
			}
			else if ((a[i] < a[2 * i + 2]) && (a[2 * i + 2] > a[2 * i + 1]))
			{	
				swap(a, i, 2 * i + 2);
				i = 2 * i + 2;
			}
			else
				i = n;
		}
		else if (a[i] < a[2 * i + 1]) //sgfwegtwe 5ey5 5y5y
		{
			swap(a, i, 2 * i + 1);
			i = 2 * i + 1;
		}
		else
			i = n;
	}
	return 0;
}

int sort(int *a, int n)
{
	while (n != 1) //ewgtwergwtf 423t4t t4rt4
	{
	swap(a, 0, n - 1);
	n--;
	screening(a, 0, n);
	}
	return 0;
}

int pSort(int *a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) //123123123
	{
		screening(a, i, n);
	}

	sort(a, n);

	return 0;
}//the end