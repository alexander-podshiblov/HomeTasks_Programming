#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        vector = new Vector<int, 3>;
    }
    void cleanup()
    {
        delete vector;
    }
    void testOfSum()
    {
        Vector<int, 3> a;
        Vector<int, 3> b;
        for(int i = 0; i < 3; i++)
        {
            a.m[i] = i + 1;
            b.m[i] = i + 2;
        }
        vector->sum(&a, &b);
        QVERIFY(vector->m[0] == 3);
        QVERIFY(vector->m[1] == 5);
        QVERIFY(vector->m[2] == 7);
    }
    void testOfSub()
    {
        Vector<int, 3> a;
        Vector<int, 3> b;
        for(int i = 0; i < 3; i++)
        {
            a.m[i] = i + 2;
            b.m[i] = i + 1;
        }
        vector->sub(&a, &b);
        QVERIFY(vector->m[0] == 1);
        QVERIFY(vector->m[1] == 1);
        QVERIFY(vector->m[2] == 1);
    }
    void testOfMult()
    {
        Vector<int, 3> a;
        Vector<int, 3> b;
        for(int i = 0; i < 3; i++)
        {
            a.m[i] = i + 2;
            b.m[i] = i + 1;
        }
        QVERIFY(vector->mult(&a, &b) == 20);
    }
    void testOfNull()
    {
        QVERIFY(vector->null());
    }
    void testOfCopy()
    {
        Vector<int, 3> a;
        for(int i = 0; i < 3; i++)
            vector->m[i] = i + 1;
        vector->copy(&a);
        QVERIFY(a.m[0] == 1);
        QVERIFY(a.m[1] == 2);
        QVERIFY(a.m[2] == 3);
    }


private:
    Vector<int, 3> *vector;
};

QTEST_MAIN(Test)
