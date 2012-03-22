#pragma once

class Stack
{
public:
    virtual void add(int value) = 0;
    virtual int empty() = 0;
    virtual void del() = 0;
    virtual int returnLast() = 0;
    virtual void removeStack() = 0;
    virtual ~Stack(){}
};
