#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sortcol.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0) {}
    
private slots:
    void testOfSort()
    {
        int **matrix = new int *[3];
        for (int i =0; i < 3; i++)
            matrix[i] = new int [3];

        matrix[0][0] = 4;
        matrix[0][1] = 5;
        matrix[0][2] = 6;
        matrix[1][0] = 7;
        matrix[1][1] = 8;
        matrix[1][2] = 9;
        matrix[2][0] = 1;
        matrix[2][1] = 2;
        matrix[2][2] = 3;

        SortCol a;
        a.sort(matrix, 3);

        int c = 1;
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j++)
            {
                QVERIFY(matrix[i][j] == c);
                c++;
            }




        for (int i =0; i < 3; i++)
            delete matrix[i];
        delete matrix;
    }
    
};

