#include <stdio.h>
#include "stack.h"
#pragma once

class PStack : public Stack
{
private:
    struct Node
    {
      int value;
      Node *next;
    };
    Node *head;
public:
    PStack();
    ~PStack();
    void add(int value);
    int empty();
    void del();
    int returnLast();
    void removeStack();
};
