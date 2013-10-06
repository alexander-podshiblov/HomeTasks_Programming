#pragma once
#include "stdio.h"

const int maxRisk = 10;

class Network
{
public:
    Network(FILE *f);
    void update();
    void printState(int step);
    bool isWinOfVirus();

private:
    int n;
    int connections[50][50];
    int os[50];
    int virus[50];

    int riskLinux;
    int riskWindows;

    bool isInfected(int risk);
    void tryToInfect(int k);

friend class Test;

};
