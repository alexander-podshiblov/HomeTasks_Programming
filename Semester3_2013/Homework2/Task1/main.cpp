#include <stdio.h>
#include "network.h"
#include "test.h"
#include <QTime>
int main()
{

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    ///*
    FILE *f = fopen("input.txt", "r");
    Network *a = new Network(f);
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
