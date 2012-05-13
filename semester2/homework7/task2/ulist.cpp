#include "ulist.h"


void UList::add(int value, int num)
{
    if (!exist(value))
        PList::add(value, num);
    else
        throw AddingExistingItem();
}

bool UList::exist(int value)
{
    Node *tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next;
        if (tmp->value == value)
            return true;
    }
    return false;
}

void UList::delValue(int value)
{
    if (exist(value))
    {
        Node *tmp = head;
        while (tmp->next->value != value)
        {
            tmp = tmp->next;
        }
        Node *tmp2 = tmp->next;
        tmp->next = tmp2->next;
        delete tmp2;
    }
    else
        throw RemovingExistingItem();
}
