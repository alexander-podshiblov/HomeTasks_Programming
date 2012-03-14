#include "list.h"
#pragma once

struct Node
{
    int value;
    Node *next;
};

class pList : public List
{
public:
    pList();
    Node *head;
    void add(int value, int num);
    int lengh();
    void del(int num);
    void printList();
    int returnValue(int num);
    void removeList();
    void swap(int i, int j);
};
