#include "bag.h"
#include <limits.h>

Bag::Bag()
{
    head = new Node;
    head->repeats = 0;
    head->value = 0;
    head->left = NULL;
    head->right = NULL;
}

Bag::~Bag()
{
    clear(head->left, &head->left);
    delete head;
}

bool Bag::exist(int value)
{
    Node *tmp = head->left;
    while (tmp != NULL)
    {
        if (tmp->value == value)
            return true;
        if (value < tmp->value)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return false;
}

void Bag::add(int value)
{
    if (head->repeats == 0)
    {
        Node *tmp = new Node;
        tmp->repeats = 1;
        tmp->value = value;
        tmp->left = NULL;
        tmp->right = NULL;
        head->left = tmp;
    }
    else if (!exist(value))
    {
        Node *tmp = head->left;
        Node *parentTmp = NULL;
        while (tmp != NULL)
        {
            parentTmp = tmp;
            if (value < tmp->value)
                tmp = tmp->left;
            else if (value > tmp->value)
                tmp = tmp->right;
        }
        tmp = new Node;
        tmp->repeats = 1;
        tmp->value = value;
        tmp->left = NULL;
        tmp->right = NULL;

        if (value < parentTmp->value)
            parentTmp->left = tmp;
        else if (value > parentTmp->value)
            parentTmp->right = tmp;
    }
    else
    {
        Node *tmp = head->left;
        while (tmp->value != value)
        {
            if (value < tmp->value)
                tmp = tmp->left;
            else if (value > tmp->value)
                tmp = tmp->right;
        }
        tmp->repeats++;
    }
    head->repeats++;
}

void Bag::del(int value)
{
    if (exist(value))
    {
        Node **parent = &head->left;
        Node *tmp = head->left;
        while (tmp->value != value)
        {

            if (tmp->value > value)
            {
                parent = &tmp->left;
                tmp = tmp->left;
            }
            else if (tmp->value < value)
            {
                parent = &tmp->right;
                tmp = tmp->right;
            }
        }
        if (tmp->repeats > 1)
            tmp->repeats--;
        else
        {
            if (tmp->left == NULL && tmp->right == NULL)
            {
                *parent = NULL;
                delete tmp;
            }
            else if (tmp->left != NULL && tmp->right == NULL)
            {
                *parent = tmp->left;
                delete tmp;
            }
            else if (tmp->left == NULL && tmp->right != NULL)
            {
                *parent = tmp->right;
                delete tmp;
            }
            else if (tmp->left != NULL && tmp->right != NULL)
            {
                Node **parent2 = &tmp->right;
                Node *tmp2 = tmp->right;
                while (tmp2->left != NULL)
                {
                    parent2 = &tmp2->left;
                    tmp2 = tmp2->left;
                }
                tmp->value = tmp2->value;
                tmp->repeats = tmp2->repeats;
                *parent2 = NULL;
                delete tmp2;
            }
        }

        head->repeats--;
    }
}

int Bag::length()
{
    return head->repeats;
}

void Bag::clear(Node *tmp, Node **parent)
{
    if (tmp != NULL)
    {
        if (tmp->left == NULL && tmp->right == NULL)
        {
            *parent = NULL;
            delete tmp;
        }
        else
        {
            if (tmp->right != NULL)
                clear(tmp->right, &tmp->right);
            if (tmp->left != NULL)
                clear(tmp->left, &tmp->left);
            clear(tmp, parent);
        }
    }
}





Bag::Iterator::Iterator(Node *tmp, Node *head1)
{
    a = tmp;
    head = head1;
    if (tmp != NULL)
        currentRepeats = a->repeats;
    else
        currentRepeats = 0;
}

Bag::Iterator Bag::begin()
{
        Node *tmp = head;
        while (tmp->left != NULL)
            tmp = tmp->left;
        if (tmp == head)
        {
            Iterator tmp2(NULL, head);
            return tmp2;
        }
        else
        {
            Iterator tmp2(tmp, head);
            return tmp2;
        }
}

Bag::Iterator Bag::end()
{
    Iterator tmp(NULL, head);
    return tmp;
}

int Bag::Iterator::returnValue()
{
    if (a != NULL)
        return a->value;
    else
        return INT_MIN;
}

int Bag::Iterator::returnRepeats()
{
    if (a != NULL)
        return a->repeats;
    else
        return INT_MIN;
}

void Bag::Iterator::bypass(Node *tmp, int value)
{
    if (tmp != NULL)
    {
        if (tmp->left == NULL && tmp->right == NULL)
        {
            if (tmp->value > value && tmp->value < nextValue)
            {
                nextValue = tmp->value;
                lastBig = tmp;
            }
        }
        else
        {
            bypass(tmp->left, value);
            if (tmp->value > value && tmp->value < nextValue)
            {
                nextValue = tmp->value;
                lastBig = tmp;
            }
            bypass(tmp->right, value);
        }

    }
}


void Bag::Iterator::operator++()
{
    if(currentRepeats > 1)
    {
        currentRepeats--;
    }
    else
    {
        Node *tmp = head->left;
        nextValue = INT_MAX;
        lastBig = NULL;
        bypass(tmp, a->value);
        if (lastBig == NULL)
            a = NULL;
        else
        {
            a = lastBig;
            currentRepeats = a->repeats;
        }
    }


}


bool Bag::Iterator::operator ==(Iterator *it)
{
    if (a != NULL && it->returnA() != NULL)
        if (a->value == it->returnValue())
            return true;
        else
            return false;
    else if (a == NULL && it->returnA() == NULL)
        return true;
    else
        return false;
}

bool Bag::Iterator::operator !=(Iterator *it)
{
    return !operator ==(it);
}

