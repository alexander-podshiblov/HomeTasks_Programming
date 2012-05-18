#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sort.h"
#include <stdio.h>

class IntComp
{
public:
    int comp(int a1, int a2)
    {
        if (a2 > a1)
            return 1;
        else
            return 0;
    }
};

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new Sort<int, IntComp>;
        b = new IntComp;
    }
    void cleanup()
    {
        delete a;
        delete b;
    }
    void TestOfSort()
    {
        int m[10] = {5, 6, 1, 3, 2, 8, 4, 0, 7, 9};
        a->BSort(m, 10, b);
        for(int i = 0; i < 10; i ++)
        {
            QVERIFY(m[i] == i);
        }
    }



private:
    Sort<int, IntComp> *a;
    IntComp *b;
};


QTEST_MAIN(Test)
