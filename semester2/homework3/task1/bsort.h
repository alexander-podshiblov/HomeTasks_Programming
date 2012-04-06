#include "sort.h"
#include <stdio.h>
#pragma once

/**
@class BSort
класс, сортирующий массив элементов типа int методом пузырьковой сортировки
*/
class BSort : public Sort
{
public:
    /**
    сортировка
    @param m - указатель на первый элемент массива
    @param n - количество элементов в массиве
    */
    void sorting(int *m, int n);
};
