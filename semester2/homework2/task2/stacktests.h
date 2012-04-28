#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "astack.h"
#include "pstack.h"

class StackTests : public QObject
{
    Q_OBJECT
public:
    explicit StackTests(QObject *parent = 0) {}

protected slots:
    virtual void init() = 0;

    virtual void cleanup()
    {
        delete a;
    }
    
    virtual void testOfAdd()
    {
        a->add(1);
        a->add(2);
        QVERIFY(a->returnLast() == 2);
    }

    virtual void returnFromEmpty()
    {
        QVERIFY(a->returnLast() == - 32000);
    }

    virtual void testOfDel()
    {
        a->add(1);
        a->add(2);
        a->del();
        QVERIFY(a->returnLast() == 1);
    }


protected:
    Stack *a;
};


class ArrayStackTests : public StackTests
{
    Q_OBJECT

private slots:
    void init()
    {
        a = new AStack();
    }

    void cleanup()
    {
        StackTests::cleanup();
    }

    void testOfAdd()
    {
        StackTests::testOfAdd();
    }

    void returnFromEmpty()
    {
        StackTests::returnFromEmpty();
    }

    virtual void testOfDel()
    {
        StackTests::testOfDel();
    }
};

class PointStackTests : public StackTests
{
    Q_OBJECT

private slots:
    void init()
    {
        a = new PStack();
    }

    void cleanup()
    {
        StackTests::cleanup();
    }

    void testOfAdd()
    {
        StackTests::testOfAdd();
    }

    void returnFromEmpty()
    {
        StackTests::returnFromEmpty();
    }

    virtual void testOfDel()
    {
        StackTests::testOfDel();
    }
};

QTEST_MAIN(ArrayStackTests);
//QTEST_MAIN(PointStackTests);


















