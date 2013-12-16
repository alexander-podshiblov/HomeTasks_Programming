#include "normalrand.h"

NormalRand::NormalRand()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
}

int NormalRand::rand()
{
    return qrand();
}
