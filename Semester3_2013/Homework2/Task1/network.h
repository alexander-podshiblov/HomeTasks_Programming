#pragma once
#include "stdio.h"
#include "computer.h"



class Network
{
public:
    Network(FILE *f, MyRand *r);
    void doStep();
    void printState(int step);
    bool isWinOfVirus();

private:
    int n;
    int connections[50][50];
    Computer *comps[50];

friend class Test;

};
