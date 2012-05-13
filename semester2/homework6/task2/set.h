#pragma once

template <typename T>
class Set
{
public:
    Set();
    ~Set();
    void add(T value);
    void del(T value);
    bool exist(T value);
    void sum(Set *a, Set *b);
    void intersect(Set *a, Set *b);

    struct Node
    {
        T value;
        Node *next;
    };

    Node *head;

};

template <typename T>
Set<T>::Set()
{
    head = new Node;
    head->next = NULL;
}

template <typename T>
Set<T>::~Set()
{
    while (head->next != NULL)
    {
        Node *tmp = head->next;
        head->next = tmp->next;
        delete tmp;
    }
    delete head;
}

template <typename T>
void Set<T>::add(T value)
{
    if (!exist(value))
    {
        Node *tmp = new Node;
        tmp->value = value;
        tmp->next = head->next;
        head->next = tmp;
    }
}

template <typename T>
void Set<T>::del(T value)
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

template <typename T>
bool Set<T>::exist(T value)
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

template <typename T>
void Set<T>::sum(Set *a, Set *b)
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

template <typename T>
void Set<T>::intersect(Set *a, Set *b)
{
    Node *tmp = a->head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (b->exist(tmp->value))
            add(tmp->value);
    }
}
