#include "sortcol.h"
#include <stdio.h>

void SortCol::sort(int **a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][0] > a[j][0])
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
}
