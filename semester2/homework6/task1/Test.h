#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "tree.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new Oper;
    }
    void cleanup()
    {
        delete a;
    }
    void TestOfTree()
    {
        char s[100] = "(/(*(+39)4)(-20))";
        a->build(s);
        QVERIFY(a->calculate() == 24);
    }
private:
    Oper *a;
};
