#include <stdio.h>
#include "stack.h"
#pragma once

class PStack : public Stack
{
public:
    PStack();
    ~PStack();
    void add(int value);
    int empty();
    void del();
    int returnLast();
    void removeStack();

private:
    struct Node
    {
      int value;
      Node *next;
    };
    Node *head;
};
