#pragma once

class Stack
{
public:
    Stack()
    {
        value = 0;
    }
    int value;
    virtual add() = 0;
    virtual lengh() = 0;
    virtual del() = 0;
    virtual printList() = 0;
    virtual returnValue() = 0;
    virtual removeList() = 0;
    virtual swap() = 0;
};
