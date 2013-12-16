#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(int risk, bool inf)
{
    setRisk(risk);

    setInf(inf);

}

void Computer::setRisk(int risk)
{
    riskOfSystem = risk;
    if (risk == 2)
        system = "Linix";
    else if (risk == 6)
        system = "Windows";
}

void Computer::setInf(bool inf)
{
    Infection = inf;
}

int Computer::getRisk()
{
    return riskOfSystem;
}

void Computer::tryToInfect()
{
    if (r->rand() % maxRisk < riskOfSystem)
        Infection = true;
    else
        Infection = false;
}

bool Computer::isInfected()
{
    return Infection;
}

void Computer::setRand(MyRand *a)
{
    r = a;
}
