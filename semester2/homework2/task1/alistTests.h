#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "alist.h"
#include "plist.h"


class ListTests : public QObject
{
    Q_OBJECT
public:
    explicit ListTests(QObject *parent = 0) {}
    
protected slots:
    virtual void init() = 0;

    virtual void cleanup()
    {
        delete a;
    }

    virtual void testOfAdding()
    {
        a->add(2,1);
        a->add(4,2);
        a->add(1,1);
        a->add(5,4);
        a->add(3,3);
        QVERIFY(a->returnValue(1) == 1);
        QVERIFY(a->returnValue(2) == 2);
        QVERIFY(a->returnValue(3) == 3);
        QVERIFY(a->returnValue(4) == 4);
        QVERIFY(a->returnValue(5) == 5);
    }

    virtual void testOfLength()
    {
        QVERIFY(a->length() == 0);
        a->add(1,1);
        a->add(2,2);
        QVERIFY(a->length() == 2);
    }

    virtual void testOfDel()
    {
        for(int i = 1; i <= 5; i++)
        {
            a->add(i,i);
        }
        a->del(5);
        a->del(3);
        a->del(1);
        QVERIFY(a->returnValue(1) == 2);
        QVERIFY(a->returnValue(2) == 4);
    }

    virtual void testOfSwap()
    {
        for(int i = 1; i <= 5; i++)
        {
            a->add(i,i);
        }
        a->swap(2,4);
        QVERIFY(a->returnValue(2) == 4);
        QVERIFY(a->returnValue(4) == 2);
    }



protected:
    List *a;
    
};

class ArrayListTests : public ListTests
{
    Q_OBJECT

private slots:
    void init()
    {
        a = new AList();
    }
    void cleanup()
    {
        ListTests::cleanup();
    }

    void testOfAdding()
    {
        ListTests::testOfAdding();
    }

    void testOfLength()
    {
        ListTests::testOfLength();
    }

    void testOfDel()
    {
        ListTests::testOfDel();
    }

    void testOfSwap()
    {
        ListTests::testOfSwap();
    }

};

class PointListTests : public ListTests
{
    Q_OBJECT

private slots:
    void init()
    {
        a = new PList();
    }
    void cleanup()
    {
        ListTests::cleanup();
    }

    void testOfAdding()
    {
        ListTests::testOfAdding();
    }

    void testOfLength()
    {
        ListTests::testOfLength();
    }

    void testOfDel()
    {
        ListTests::testOfDel();
    }

    void testOfSwap()
    {
        ListTests::testOfSwap();
    }

};

QTEST_MAIN(ArrayListTests)
//QTEST_MAIN(PointListTests)
