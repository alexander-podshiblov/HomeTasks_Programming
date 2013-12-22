#include "zeroElements.h"

int zeroElements(int *m, int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
        if(m[i] == 0)
            n++;
    return n;
}
