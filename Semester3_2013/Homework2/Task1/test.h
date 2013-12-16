#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "network.h"
#include "testrand.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}

private slots:
    void init()
    {
        FILE *f = fopen("input.txt","r");
        r = new TestRand();
        a = new Network(f, r);
        fclose(f);
    }
    void cleanup()
    {
        delete a;
    }
    void MainTest()
    {
        //Step0
        QVERIFY(!a->comps[0]->isInfected());
        QVERIFY(!a->comps[1]->isInfected());
        QVERIFY(a->comps[2]->isInfected());
        QVERIFY(!a->comps[3]->isInfected());
        QVERIFY(a->comps[4]->isInfected());

        //Step1
        a->doStep();
        QVERIFY(!a->comps[0]->isInfected());
        QVERIFY(a->comps[1]->isInfected());
        QVERIFY(a->comps[2]->isInfected());
        QVERIFY(!a->comps[3]->isInfected());
        QVERIFY(a->comps[4]->isInfected());

        //Step2
        a->doStep();
        QVERIFY(a->comps[0]->isInfected());
        QVERIFY(a->comps[1]->isInfected());
        QVERIFY(a->comps[2]->isInfected());
        QVERIFY(!a->comps[3]->isInfected());
        QVERIFY(a->comps[4]->isInfected());

        //Step3
        a->doStep();
        QVERIFY(a->comps[0]->isInfected());
        QVERIFY(a->comps[1]->isInfected());
        QVERIFY(a->comps[2]->isInfected());
        QVERIFY(!a->comps[3]->isInfected());
        QVERIFY(a->comps[4]->isInfected());

        //Step4
        a->doStep();
        QVERIFY(a->comps[0]->isInfected());
        QVERIFY(a->comps[1]->isInfected());
        QVERIFY(a->comps[2]->isInfected());
        QVERIFY(a->comps[3]->isInfected());
        QVERIFY(a->comps[4]->isInfected());

    }



private:
    Network *a;
    MyRand *r;
};
