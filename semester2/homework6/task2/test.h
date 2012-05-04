#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "set.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new Set<int>;
    }
    void cleanup()
    {
        delete a;
    }

    void testOfAdd()
    {
        a->add(2);
        a->add(1);
        QVERIFY(a->head->next->value == 1);
        QVERIFY(a->head->next->next->value == 2);
    }
    void testOfExist()
    {
        a->add(1);
        a->add(2);
        a->add(3);
        QVERIFY(a->exist(3));
        QVERIFY(a->exist(2));
        QVERIFY(a->exist(1));
    }
    void testOfDel()
    {
        a->add(5);
        a->add(4);
        a->add(3);
        a->add(2);
        a->add(1);
        a->del(5);
        a->del(3);
        a->del(1);
        QVERIFY(!a->exist(5));
        QVERIFY(!a->exist(3));
        QVERIFY(!a->exist(1));
    }
    void testOfSum()
    {
        Set<int> *k1 = new Set<int>;
        Set<int> *k2 = new Set<int>;

        k1->add(1);
        k1->add(2);
        k2->add(2);
        k2->add(3);

        a->sum(k1, k2);

        for (int i = 1; i <= 3; i++)
            QVERIFY(a->exist(i));

        delete k1;
        delete k2;
    }
    void testOfIntersect()
    {
        Set<int> *k1 = new Set<int>;
        Set<int> *k2 = new Set<int>;

        k1->add(1);
        k1->add(2);
        k2->add(2);
        k2->add(3);

        a->intersect(k1, k2);

        QVERIFY(a->exist(2));
        QVERIFY(!a->exist(1));
        QVERIFY(!a->exist(3));
    }

private:
    Set<int> *a;
};

QTEST_MAIN(Test)
