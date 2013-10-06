#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "network.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        FILE *f = fopen("input.txt","r");
        a = new Network(f);
        fclose(f);
        a->riskLinux = 0;
        a->riskWindows = 10;
    }
    void cleanup()
    {
        delete a;
    }
    void mainTest()
    {
        a->update();
        QVERIFY(a->virus[0] == 1);
        QVERIFY(a->virus[3] == 0);
    }



private:
    Network *a;
};
