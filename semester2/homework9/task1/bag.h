#include <stdio.h>
#pragma once

class Bag
{
public:
    Bag();
    ~Bag();
    bool exist(int value);
    void add(int value);
    void del(int value);
    int length();
    void iterator();


private:
    struct Node
    {
        int repeats; //в head это поле хранит кол-во элементов в множестве
        int value;
        Node *left;
        Node *right;
    };
    Node *head;
    void clear(Node *tmp, Node **parent);
    void it(Node *tmp);
};
