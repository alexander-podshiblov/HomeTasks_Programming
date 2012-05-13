#include <stdio.h>
#include "list.h"
#pragma once

class PList : public List
{
public:
    PList();
    virtual ~PList();
    virtual void add(int value, int num);
    virtual int length();
    virtual void del(int num);
    virtual void printList();
    virtual int returnValue(int num);
    virtual void removeList();
    virtual void swap(int i, int j);

protected:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *head;
};
