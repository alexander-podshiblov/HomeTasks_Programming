#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "alist.h"


class AlistTests : public QObject
{
    Q_OBJECT
public:
    explicit AlistTests(QObject *parent = 0) {}
    
private slots:
    void init()
    {
        a = new AList();
    }

    void cleanup()
    {
        delete a;
    }

    void testOfAdding()
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






private:
    List *a;
    
};

QTEST_MAIN(AlistTests)
