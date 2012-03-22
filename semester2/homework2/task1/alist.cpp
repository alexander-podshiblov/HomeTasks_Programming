#include <stdio.h>
#include "alist.h"

AList::AList()
{
    maxSize = 300;
    m = new int[maxSize + 1];
    m[0] = 0;
}

AList::~AList()
{
    delete[] m;
}

void AList::add(int value, int num)
{
    if (m[0] < maxSize)
    {
        if ((num >= 1) && (num <= m[0]))
        {
            for (int i = m[0]; i >= num; i--)
                m[i + 1] = m[i];
            m[num] = value;
        }
        else if (num > m[0])
            m[m[0] + 1] = value;
        m[0]++;
    }
}

int AList::length()
{
    return m[0];
}

void AList::del(int num)
{
    if ((num >= 1) && (num <= m[0]))
        for (int i = num; i < m[0]; i++)
            m[i] = m[i + 1];
    m[0]--;
}

void AList::removeList()
{
    m[0] = 0;
}

int AList::returnValue(int num)
{
    if ((num >= 1) && (num <= m[0]))
        return m[num];
    else
        return -32000;
}

void AList::printList()
{
    for (int i = 1; i <= m[0]; i++)
        printf("%i ", m[i]);
}

void AList::swap(int i, int j)
{
    if ((i >= 1) && (j >= 1) && (i <= m[0]) && (j <= m[0]))
    {
        int tmp = m[i];
        m[i] = m[j];
        m[j] = tmp;
    }
}
