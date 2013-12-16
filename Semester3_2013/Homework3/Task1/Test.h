#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "robograph.h"
#include <string.h>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new RoboGraph();
    }
    void cleanup()
    {
        delete a;
        fclose(f);
    }
    void testOne()
    {
        f = fopen("input.txt", "r");
        a->setFile(f);
        a->analise();
        QVERIFY(a->getAnswer());
    }
    void testTwo()
    {
        f = fopen("input2.txt", "r");
        a->setFile(f);
        a->analise();
        QVERIFY(a->getAnswer());
    }
    void testThree()
    {
        f = fopen("input3.txt", "r");
        a->setFile(f);
        a->analise();
        QVERIFY(!a->getAnswer());
    }

private:
    RoboGraph *a;
    FILE *f;
};
