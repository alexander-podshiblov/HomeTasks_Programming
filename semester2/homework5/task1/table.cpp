#include "table.h"
#include <stdio.h>

Table::Table()
{
    size = 500;
    m = new Node *[size];
    for (int i = 0; i < size; i++)
        m[i] = NULL;
    function = new Func1;
}

Table::~Table()
{
    for (int i = 0; i < size; i++)
    {
        while (m[i] != NULL)
        {
            Node *tmp = m[i];
            m[i] = m[i]->next;
            delete tmp;
        }
    }
    delete[] m;
    delete function;
}

void Table::add(char *s)
{
    int key = function->hash(s, size);
    Node *tmp = new Node;
    strcpy(tmp->str, s);
    tmp->next = m[key];
    m[key] = tmp;
}

void Table::del(char *s)
{
    int key = function->hash(s, size);
    if (m[key] == NULL)
    {}
    else if (strcmp(m[key]->str, s) == 0)
    {
        Node *tmp = m[key];
        m[key] = m[key]->next;
        delete tmp;
    }
    else
    {
        Node *tmp = m[key];
        while (strcmp(tmp->next->str, s) != 0 && tmp->next != NULL)
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
}

bool Table::exist(char *s)
{
    int key = function->hash(s, size);
    if (m[key] == NULL)
        return false;
    else
    {
        Node *tmp = m[key];
        while(strcmp(tmp->str, s) != 0 && tmp->next != NULL)
            tmp = tmp->next;
        if (strcmp(tmp->str, s) == 0)
            return true;
        else
            return false;

    }
}

int Table::cells()
{
    return size;
}

void Table::stats()
{
    double k = 0;
    lconf = 0;
    conflicts = 0;
    for (int i = 0; i < size; i++)
    {
        int tmp1 = 0;
        if (m[i] != NULL)
        {
            Node *tmp = m[i];
            k++;
            tmp1++;
            if (tmp->next != NULL)
                conflicts++;
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
                k++;
                tmp1++;
            }
        }
        if (lconf < tmp1)
            lconf = tmp1;
    }
    loadFactor = k / size;
}

void Table::changeFunc(HashFunc *f)
{
    function = f;
    rebuild();
}

void Table::rebuild()
{
    m2 = new Node *[size];
    for (int i = 0; i < size; i++)
        m2[i] = NULL;

    Node **l;
    l = m;
    m = m2;
    m2 = l;

    for (int i = 0; i < size; i++)
    {
        if (m2[i] != NULL)
        {
            while (m2[i] != NULL)
            {
                add(m2[i]->str);
                Node *tmp = m2[i];
                m2[i] = m2[i]->next;
                delete tmp;
            }
        }
    }
    delete[] m2;

}
