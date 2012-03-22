#include <stdio.h>
#include "list.h"
#pragma once

class PList : public List
{
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *head;
public:
    PList();
    ~PList();
    void add(int value, int num);
    int length();
    void del(int num);
    void printList();
    int returnValue(int num);
    void removeList();
    void swap(int i, int j);
};
