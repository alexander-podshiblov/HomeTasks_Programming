#include <stdio.h>
#include "network.h"
#include "test.h"
#include <QTime>
#include "normalrand.h"
int main()
{



    ///*
    MyRand *rand = new NormalRand();
    FILE *f = fopen("input.txt", "r");
    Network *a = new Network(f, rand);
    fclose(f);

    int iterator = 2;

    a->printState(1);
    while(!a->isWinOfVirus())
    {

        a->doStep();
        a->printState(iterator);
        iterator++;
    }
    //*/
    Test test;
    QTest::qExec(&test);

    return 0;
}
