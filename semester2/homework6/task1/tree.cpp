#include "tree.h"

Tree::Tree()
{
    left = NULL;
    right = NULL;
}

Tree::~Tree()
{
    delete left;
    delete right;
}

Num::Num(int a)
{
    value = a;
}

int Num::calculate()
{
    return value;
}

void Num::print()
{
    printf("%i ", value);
}

int Oper::calculate()
{
    int l = left->calculate();
    int r = right->calculate();
    if (c == '+')
        return l + r;
    if (c == '-')
        return l - r;
    if (c == '*')
        return l * r;
    if (c == '/')
        return l / r;
}

void Oper::print()
{

    printf("(%c", c);
    left->print();
    right->print();
    printf(")");
}

void Oper::shift(char *s)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
        s[i] = s[i + 1];
}

void Oper::build(char *string)
{
    shift(string);
    c = string[0];
    shift(string);
    if(string[0] == '(')
    {
        Oper *tmp = new Oper;
        left = tmp;
        tmp->build(string);
    }
    else
        left = new Num(string[0] - '0');
    shift(string);
    if(string[0] == '(')
    {
        Oper *tmp = new Oper;
        right = tmp;
        tmp->build(string);
    }
    else
        right = new Num(string[0] - '0');
    shift(string);

}





