#include <stdio.h>
#pragma once

template <typename T>
class PQueue
{
public:
    class EmptyList {};
    PQueue()
    {
        head = new Node;
        head->next = NULL;
    }

    ~PQueue()
    {
        while (head->next != NULL)
        {
            Node *tmp = head->next;
            head->next = tmp->next;
            delete tmp;
        }
        delete head;
    }

    void enqueue(T value, int priority)
    {
        Node *tmp = head;
        while ((tmp->next != NULL) && (priority < tmp->next->priority))
            tmp = tmp->next;
        Node *tmp2 = new Node;
        tmp2->next = tmp->next;
        tmp2->value = value;
        tmp2->priority = priority;
        tmp->next = tmp2;
    }

    T dequeue()
    {
        if (head->next != NULL)
        {
            T k;
            Node *tmp = head->next;
            head->next = tmp->next;
            k = tmp->value;
            delete tmp;
            return k;
        }
        else
            throw EmptyList();
    }

private:
    struct Node
    {
        int priority;
        T value;
        Node *next;
    };

    Node *head;
};

