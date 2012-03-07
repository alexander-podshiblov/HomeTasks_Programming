#include "pstack.h"

pStack::pStack()
{
    next = NULL;
}
pStack::add(pStack *head, int value)
{
    pStack *tmp = new pStack;
    tmp->value = value;
    tmp->next = head->next;
    head->next = tmp;
}
