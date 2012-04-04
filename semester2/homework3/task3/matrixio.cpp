#include "matrixio.h"
#include <stdio.h>

void MatrixIO::scan(FILE *stream, int **a, int m, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(stream, "%i", &a[j][i]);
}

void MatrixIO::print(FILE *stream, int **a, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            fprintf(stream, "%5i ", a[j][i]);
        fprintf(stream, "\n");
    }
}
