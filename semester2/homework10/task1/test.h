#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "game.h"


class Test : public QObject
{
    Q_OBJECT

private slots:
    void init()
    {
        g = new Game;
    }
    void cleanup()
    {
        delete g;
    }
    void testOfLines()
    {
        for (int i = 0; i < 9; i = i + 3)
        {
            g->m[i] = 1;
            g->m[i + 1] = 1;
            g->m[i + 2] = 1;
            QVERIFY(g->checkOfWinner() == 1);
            g->m[i] = 0;
            g->m[i + 1] = 0;
            g->m[i + 2] = 0;
        }
    }
    void testOfColumns()
    {
        for (int i = 0; i < 3; i++)
        {
            g->m[i] = 1;
            g->m[i + 3] = 1;
            g->m[i + 6] = 1;
            QVERIFY(g->checkOfWinner() == 1);
            g->m[i] = 0;
            g->m[i + 3] = 0;
            g->m[i + 6] = 0;
        }
    }
    void testOfDiag()
    {
        g->m[0] = 1;
        g->m[4] = 1;
        g->m[8] = 1;
        QVERIFY(g->checkOfWinner() == 1);
        g->m[0] = 0;
        g->m[4] = 0;
        g->m[8] = 0;

        ///////////

        g->m[2] = 1;
        g->m[4] = 1;
        g->m[6] = 1;
        QVERIFY(g->checkOfWinner() == 1);
        g->m[2] = 0;
        g->m[4] = 0;
        g->m[6] = 0;
    }



private:
    Game *g;
};
