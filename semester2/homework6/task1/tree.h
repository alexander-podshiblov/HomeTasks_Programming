#include <string.h>
#include <stdio.h>
#include <Windows.h>
#pragma once

class Tree
{
public:
    Tree();
    virtual ~Tree();
    virtual int calculate() = 0;
    virtual void print(int x1, int x2, int depth) = 0;
protected:
    Tree *left;
    Tree *right;
    void gotoxy(int x, int y);
};

class Num : public Tree
{
public:
    Num(int a);
    int calculate();
    void print(int x1, int x2, int depth);
private:
    int value;
};

class Oper : public Tree
{
public:
    int calculate();
    void print(int x1, int x2, int depth);
    void build(char *string);
private:
    char c;
    void shift(char *s);
};

