#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "psort.h"
#include "bsort.h"

#include <QObject>

class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0) {}
    
private slots:
    void testOfBSort()
    {
        BSort a;
        int m[17] = {4, 65, 45, 87, 98, 123, 16, 136, 122, 1, -65, 54, -7, 0, 1, -300, 8};
        a.sorting(m, 17);
        for (int i = 1; i < 17; i++)
        {
            QVERIFY(m[i] >= m[i - 1]);
        }
    }

    void testOfPSort()
    {
        PSort a;
        int m[17] = {4, 65, 45, 87, 98, 123, 16, 136, 122, 1, -65, 54, -7, 0, 1, -300, 8};
        a.sorting(m, 17);
        for (int i = 1; i < 17; i++)
        {
            QVERIFY(m[i] >= m[i - 1]);
        }
    }


};
