#include <stdio.h>
#include "matrixio.h"
#include "sortcol.h"

int main()
{
    int n = 0;
    int m = 0;
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%i %i", &m, &n);

    int **matrix = new int *[m];
    for (int i =0; i < m; i++)
        matrix[i] = new int [n];

    MatrixIO s;
    s.scan(f, matrix, m, n);

    fclose(f);

    SortCol l;
    l.sort(matrix, m);

    f = fopen("output.txt", "w");
    s.print(f, matrix, m, n);
    fclose(f);


    for (int i =0; i < m; i++)
        delete matrix[i];
    delete matrix;
    return 0;
}
