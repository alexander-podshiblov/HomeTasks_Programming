#include <stdio.h>
#include "stack.h"
#pragma once

class AStack : public Stack
{
public:
    AStack();
    ~AStack();
    void add(int value);
    int empty();
    void del();
    int returnLast();
    void removeStack();

private:
    int *m;
    int maxSize;
};

