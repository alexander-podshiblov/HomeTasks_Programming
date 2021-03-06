#include <stdio.h>
#include "list.h"
#pragma once

class AList : public List
{
public:
    AList();
    ~AList();
    void add(int value, int num);
    int length();
    void del(int num);
    void printList();
    int returnValue(int num);
    void removeList();
    void swap(int i, int j);

private:
    int *m;
    int maxSize;
};

