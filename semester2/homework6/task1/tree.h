#include <string.h>
#include <stdio.h>
#pragma once

class Tree
{
public:
    Tree();
    virtual ~Tree();
    virtual int calculate() = 0;
    virtual void print() = 0;
protected:
    Tree *left;
    Tree *right;
};

class Num : public Tree
{
public:
    Num(int a);
    int calculate();
    void print();
private:
    int value;
};

class Oper : public Tree
{
public:
    int calculate();
    void print();
    void build(char *string);
private:
    char c;
    void shift(char *s);
};

