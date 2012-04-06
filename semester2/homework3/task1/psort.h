#include "sort.h"
#include <stdio.h>
#pragma once

/**
@class PSort
класс, сортирующий массив элементов типа int методом пирамидальной сортировки
*/
class PSort : public Sort
{
public:
    /**
    метод, сортирующий массив
    @param m - указатель на первый элемент массива
    @param n - количество элементов в массиве
    */
    void sorting(int *m, int n);

private:
    /**
    меняет местами два элемента массива
    @param a - указатель на первый элемент массива
    @param i - индекс первого элемента
    @param j - индекс второго элемента
    */
    void swap(int *a, int i, int j);
    /**
    "просеивание" элемента
    @param a - указатель на первый элемент массива
    @param i - индекс элемента
    @param n - количество элементов в массиве
    */
    void screening(int *a, int i, int n);
    /**
    окончательная сортировка
    @param a - указатель на первый элемент массива
    @param n - количество элементов в массиве
    */
    void sort(int *a, int n);
};

