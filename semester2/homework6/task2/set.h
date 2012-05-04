#pragma once

template <typename T>
class Set
{
public:
    Set()
    {
        head = new Node;
        head->next = NULL;
    }
    ~Set()
    {
        while (head->next != NULL)
        {
            Node *tmp = head->next;
            head->next = tmp->next;
            delete tmp;
        }
        delete head;
    }
    void add(T value)
    {
        Node *tmp = new Node;
        tmp->value = value;
        tmp->next = head->next;
        head->next = tmp;
    }
    void del(T value)
    {
        Node *tmp = head;
        while (tmp->next != NULL && tmp->next->value != value)
        {
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
        {
            Node *tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
        }
    }
    bool exist(T value)
    {
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            if (tmp->value == value)
                return true;
        }
        return false;
    }
    void sum(Set *a, Set *b)
    {
        Node *tmp = a->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            add(tmp->value);
        }

        tmp = b->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            if (!exist(tmp->value))
                add(tmp->value);
        }
    }
    void intersect(Set *a, Set *b)
    {
        Node *tmp = a->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            if (b->exist(tmp->value))
                add(tmp->value);
        }
    }

    struct Node
    {
        T value;
        Node *next;
    };

    Node *head;

};


