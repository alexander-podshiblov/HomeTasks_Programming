#include <stdio.h>
#include "sort.h"
#include "bsort.h"
#include "psort.h"

void printArray(int *m, int n)
{
    for (int i = 0; i < n; i++)
        printf("%i ", m[i]);
}

int main()
{
    int m[500];
    int n = 0;
    FILE *f = fopen("input.txt", "r");
    fscanf(f, "%i", &n);
    for (int i = 0; i < n; i++)
        fscanf(f, "%i ", &m[i]);
    fclose(f);


    printf("Your array:\n");
    printArray(m, n);
    printf("\n\n");

    printf("Use the sort:\n  1. Hip\n  2. Bubble\n  (1/2) ?\n\n  ");
    int ch = 0;
    scanf("%i", &ch);

    Sort *z;
    if (ch == 1)
        z = new PSort;
    else if (ch == 2)
        z = new BSort;

    z->sorting(m, n);

    printf("Your sorted array:\n");
    printArray(m, n);

    delete z;
    scanf("%*");
    return 0;
}
