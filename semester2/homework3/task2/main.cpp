#include <stdio.h>
#include "outputer.h"




int main()
{
    int *m = new int [1000];
    FILE *f = fopen("input.txt", "r");
    int n = 0;
    fscanf(f, "%i", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(f, "%i", &m[i * n + j]);
    }
    fclose(f);

    printf("Your matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3i ", m[i * n + j]);
        printf("\n");
    }
    printf("Output to the console or in the file (c/f)? ");
    char ch = 0;
    scanf("%c", &ch);

    if (ch == 'c')
        f = stdout;
    else if (ch == 'f')
        f = fopen("output.txt", "w");

    printf("\n\n");

    Outputer k;
    k.bypass(m, n, f);

    if (ch == 'f')
        fclose(f);
    delete m;
    return 0;
}
