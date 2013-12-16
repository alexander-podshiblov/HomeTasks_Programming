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
    }
    void cleanup()
    {
        delete a;
    }
    void aTest()
    {

    }



private:
    Network *a;
};
