#include <stdio.h>
#include "robograph.h"

int main()
{
    FILE *f = fopen("input.txt", "r");
    RoboGraph *a = new RoboGraph(f);

    a->analise();

    if (a->getAnswer())
        printf("\n YES");
    else
        printf("\n NO");

    delete a;
    fclose(f);
    return 0;
}
