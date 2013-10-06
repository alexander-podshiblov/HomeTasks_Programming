#include <stdio.h>
#include "network.h"
#include "test.h"

int main()
{
    ///*
    FILE *f = fopen("input.txt", "r");
    Network *a = new Network(f);
    fclose(f);

    int iterator = 2;

    a->printState(1);
    while(!a->isWinOfVirus())
    {

        a->update();
        a->printState(iterator);
        iterator++;
    }
    //*/
    Test test;
    QTest::qExec(&test);

    return 0;
}
