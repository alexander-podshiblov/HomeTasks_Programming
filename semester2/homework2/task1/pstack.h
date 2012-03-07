#pragma once

class pStack : public Stack
{
public:
    pStack();
private:
    pStack *next;
};
