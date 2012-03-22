#include <stdio.h>
#include "astack.h"

AStack::AStack()
{
    maxSize = 300;
    m = new int[maxSize + 1];
    m[0] = 0;
}

AStack::~AStack()
{
    delete[] m;
}

void AStack::add(int value)
{
    if (m[0] < maxSize)
    {
        m[m[0] + 1] = value;
        m[0]++;
    }
}

void AStack::del()
{
    m[0]--;
}

int AStack::empty()
{
    if (m[0] == 0)
        return 1;
    else
        return 0;
}

int AStack::returnLast()
{
    return m[m[0]];
}

void AStack::removeStack()
{
    m[0] = 0;
}
