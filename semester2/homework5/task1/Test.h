#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "func.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void testOfDifferenceFunc()
    {
        Func1 a;
        Func2 b;
        char s[50] = "String for testing difference of functions";
        QVERIFY(a.hash(s, 500) != b.hash(s, 500));
    }

};
