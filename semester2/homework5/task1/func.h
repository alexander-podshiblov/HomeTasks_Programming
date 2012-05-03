#include "hashfunc.h"
#pragma once

class Func1 : public HashFunc
{
public:
    int hash(char *s, const int size);
};

class Func2 : public HashFunc
{
public:
    int hash(char *s, const int size);
};
