#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"
#include <string.h>

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new Bag;
    }
    void cleanup()
    {
        delete a;
    }
    void TestOfAdd()
    {
        a->add(6);
        a->add(1);
        a->add(4);
        a->add(9);
        a->add(2);
        a->add(8);
        a->add(3);
        a->add(5);
        a->add(7);
        a->add(10);
        for (int i = 1; i <= 10; i++)
        {
            QVERIFY(a->exist(i));
        }
    }
    void TestOfDel()
    {
        a->add(6);
        a->add(1);
        a->add(4);
        a->add(9);
        a->add(2);
        a->add(8);
        a->add(3);
        a->add(5);
        a->add(7);
        a->add(10);
        a->del(7);
        a->del(3);
        for (int i = 1; i <= 10; i++)
        {
            if (i != 7 && i != 3)
                QVERIFY(a->exist(i));
        }
        QVERIFY(!a->exist(3));
        QVERIFY(!a->exist(7));
    }
    void TestOfAddAndDel()
    {
        a->add(1);
        a->add(2);
        a->add(2);
        a->add(2);
        a->del(2);
        QVERIFY(a->length() == 3);
    }






private:
    Bag *a;
};
