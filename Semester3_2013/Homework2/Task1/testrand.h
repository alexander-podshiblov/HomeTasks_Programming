#pragma once
#include "myrand.h"

class TestRand : public MyRand
{
public:
    TestRand();
    int rand();
private:
    static int numbers[9];
    int i;
};

