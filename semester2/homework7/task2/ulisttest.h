#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "ulist.h"

class UListTests : public QObject
{
    Q_OBJECT
public:
    explicit UListTests(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new UList;
    }
    void cleanup()
    {
        delete a;
    }
    void testOfExist()
    {
        a->add(3, 1);
        a->add(2, 1);
        a->add(1, 1);
        QVERIFY(a->exist(2));
    }

    void testOfAdd()
    {
        a->add(1, 1);
        int error = 0;
        try
        {
            a->add(1, 2);
        }
        catch (AddingExistingItem)
        {
            error = INT_MIN;
        }
        QVERIFY(error == INT_MIN);
    }

    void testOfDelValue()
    {
        int error = 0;
        try
        {
            a->delValue(2);
        }
        catch (RemovingExistingItem)
        {
            error = INT_MAX;
        }
        QVERIFY(error == INT_MAX);
    }


private:
    UList *a;
};
