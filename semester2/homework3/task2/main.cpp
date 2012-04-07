#include <stdio.h>
#include "outputer.h"
#include "inconsole.h"
#include "infile.h"

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

    Outputer *k;

    if (ch == 'c')
        k = new InConsole;
    else if (ch == 'f')
        k = new InFile;

    printf("\n\n");

    k->bypass(m, n);

    delete k;
    delete m;
    return 0;
}
