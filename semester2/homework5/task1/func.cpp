#include "func.h"

#pragma once

int Func1::hash(char *s, const int size)
{
    const int p = 59;
    unsigned long long pPower = 1;
    unsigned long long hash = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        hash = hash + s[i] * pPower;
        pPower = pPower * p;
    }
    return hash % size;
}

int Func2::hash(char *s, const int size)
{
    const int p = 59;
    unsigned long long pPower = 1;
    unsigned long long hash = 0;
    int n = strlen(s);
    for (int i = n; i >= 0; i--)
    {
        hash = hash + s[i] * pPower;
        pPower = pPower * p;
    }
    return hash % size;
}
