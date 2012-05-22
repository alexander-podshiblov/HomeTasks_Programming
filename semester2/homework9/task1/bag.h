#include <stdio.h>
#pragma once

class Bag
{
public:
    struct Node
    {
        int repeats; //в head это поле хранит кол-во элементов в множестве
        int value;
        Node *left;
        Node *right;
    };

    class Iterator
    {
    public:
        Iterator() {a = NULL; head = NULL; currentRepeats = 0;}
        Iterator(Node *tmp, Node *head1);
        int returnValue();
        int returnRepeats();
        Node* returnA(){return a;}
        void operator++();
        bool operator==(Iterator *it);
        bool operator!=(Iterator *it);
    private:
        Node *a;
        Node *head;
        int currentRepeats;
        void bypass(Node *tmp, int value);
        int nextValue;
        Node* lastBig;


    };


    Bag();
    ~Bag();
    bool exist(int value);
    void add(int value);
    void del(int value);
    int length();
    Iterator begin();
    Iterator end();

private:
    Node *head;
    void clear(Node *tmp, Node **parent);

};
