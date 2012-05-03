#pragma once
#include <string.h>

/**
@class HashFunc
класс, считающий хеш-функцию от строки
*/
class HashFunc
{
public:
    /**
    сортировка
    @param s - указатель на первый элемент строки
    @param size - количество ячеек в хеш-таблице
    */
    virtual int hash(char *s, const int size) = 0;
};

