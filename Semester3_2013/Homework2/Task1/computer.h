#pragma once
#include <QString>
#include <myrand.h>

const int maxRisk = 10;
const int riskOfLinux = 2;
const int riskOfWindows = 6;

class Computer
{
public:
    Computer();
    Computer(int risk, bool inf);
    void setRand(MyRand *a);
    void tryToInfect();
    int getRisk();
    void setRisk(int risk);
    void setInf(bool inf);
    bool isInfected();
private:
    int riskOfSystem;
    bool Infection;
    QString system;
    MyRand *r;
};
