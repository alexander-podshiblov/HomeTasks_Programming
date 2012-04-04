#include "outputer.h"
#include <stdio.h>

void Outputer::bypass(int *m, int n, FILE *stream)
{
    int path = 1;
    int c = 0;
    int i = n / 2;
    int j = n / 2;

    fprintf(stream, "%i ", m[i * n + j]);
    while ((i != n - 1) || (j != 0))
    {
        c = 0;
        while (c < path)
        {
            i--;
            c++;
            fprintf(stream, "%i ", m[i * n + j]);
        }
        c = 0;
        while (c < path)
        {
            j++;
            c++;
            fprintf(stream, "%i ", m[i * n + j]);
        }
        c = 0;
        path++;
        while (c < path)
        {
            i++;
            c++;
            fprintf(stream, "%i ", m[i * n + j]);
        }
        c = 0;
        while (c < path)
        {
            j--;
            c++;
            fprintf(stream, "%i ", m[i * n + j]);
        }
        path++;
    }
    for (i = n - 1; i >= 0; i --)
        fprintf(stream, "%i ", m[i * n + j]);
}
