#pragma once

/**
@class Sort
интерфейс сортировщика массива элементов типа int
*/
class Sort
{
public:
/**
метод, сортирующий массив
@param m - указатель на первый элемент массива
@param n - количество элементов в массиве
*/
    virtual void sorting(int *m, int n) = 0;
};
