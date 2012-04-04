#include "bsort.h"
#include <stdio.h>

void BSort::sorting(int *m, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (m[i] > m[j])
            {
                int k = m[i];
                m[i] = m[j];
                m[j] = k;
            }
        }
    }
}
