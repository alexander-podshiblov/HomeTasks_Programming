#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <zeroElements.h>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        size = 8;
        m = new int[size];
        for(int i = 0; i < size; i++)
            m[i] = qrand() + 1;
    }
    void test1()
    {
        m[0] = 0;
        m[4] = 0;
        m[7] = 0;
        QVERIFY(zeroElements(m, size) == 3);

    }
    void test2()
    {
        m[6] = 0;
        QVERIFY(zeroElements(m, size) == 1);
    }
    void test3()
    {
        QVERIFY(zeroElements(m, size) == 0);
    }
    void test4()
    {
        for(int i = 0; i < size; i++)
            m[i] = 0;
        QVERIFY(zeroElements(m, size) == size);
    }

    void cleanup()
    {
        delete[] m;
    }


private:
    int *m;
    int size;
};
