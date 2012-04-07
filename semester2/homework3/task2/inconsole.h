#include "outputer.h"
#include <stdio.h>
#pragma once
/**
@class InConsole
Класс, выводящий матрицу по спирали в консоль
*/
class InConsole : public Outputer
{
public:
    /**
    печатает элемент в консоль
    @param elem - элемент для печати
    */
    void print(int elem);
};

