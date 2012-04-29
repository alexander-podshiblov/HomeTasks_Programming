#include <stdio.h>
#include "pstack.h"

PStack::PStack()
{
    head = new Node;
    head->value = 0;
    head->next = NULL;
}

PStack::~PStack()
{
    removeStack();
    delete head;
}

void PStack::add(int value)
{
    Node *tmp = new Node;
    tmp->value = value;
    tmp->next = head->next;
    head->next = tmp;
}

int PStack::empty()
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}

void PStack::del()
{
    Node *tmp = head->next;
    head->next = tmp->next;
    delete tmp;
}

int PStack::returnLast()
{
    if (head->next == NULL)
        return -32000;
    else
        return head->next->value;
}

void PStack::removeStack()
{
    while (empty() == 0)
        del();
}
