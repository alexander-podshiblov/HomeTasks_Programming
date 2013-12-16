#pragma once
#include "myrand.h"
#include <QTime>

class NormalRand : public MyRand
{
public:
    NormalRand();
    int rand();
};

