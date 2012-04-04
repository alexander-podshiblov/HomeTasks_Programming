#include "psort.h"
#include <stdio.h>

void PSort::swap(int *a, int i, int j)
{
    int k = a[i];
    a[i] = a[j];
    a[j] = k;
}

void PSort::screening(int *a, int i, int n)
{
    while (2 * i + 2 <= n)
        {
            if (2 * i + 2 < n)
            {
                if ((a[i] < a[2 * i + 1]) && (a[2 * i + 1] >= a[2 * i + 2]))
                {
                    swap(a, i, 2 * i + 1);
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
            else if (a[i] < a[2 * i + 1])
            {
                swap(a, i, 2 * i + 1);
                i = 2 * i + 1;
            }
            else
                i = n;
        }
}

void PSort::sort(int *a, int n)
{
    while (n != 1)
        {
        swap(a, 0, n - 1);
        n--;
        screening(a, 0, n);
        }
}

void PSort::sorting(int *m, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        {
            screening(m, i, n);
        }

    sort(m, n);
}
