#include "outputer.h"
#include <stdio.h>
#pragma once
/**
@class InFile
Класс, выводящий матрицу по спирали в файл "output.txt"
*/
class InFile : public Outputer
{
public:
    /// инициализирует указатель на файл
    InFile();
    /// закрывает файл по окончании вывода
    ~InFile();
    /**
    печатает элемент в файл
    @param elem - элемент для печати
    */
    void print(int elem);
private:
    /// указатель на файл
    FILE *f;
};
