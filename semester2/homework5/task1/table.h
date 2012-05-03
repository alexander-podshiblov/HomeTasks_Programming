#pragma once
#include "func.h"


class Table
{
public:
    Table();
    ~Table();
    //добавляет строку в хеш-таблицу
    void add(char *s);
    //удаляет строку из хеш-таблицы
    void del(char *s);
    //проверяет существование строки в хеш-таблице
    bool exist(char *s);
    //возвращает кол-во ячеек в хеш-таблице
    int cells();
    //заполняет статистические поля класса
    void stats();
    //меняет хеш-функцию и перестраивает таблицу
    void changeFunc(HashFunc *f);
    //перестраивает таблицу
    void rebuild();

    //отношение записей в таблице к числу ячеек
    double loadFactor;
    //число конфликтов
    int conflicts;
    //максимальная длина конфликтной цепочки
    int lconf;



private:
    //элемент списка значений
    struct Node
    {
        char str[200];
        Node *next;
    };
    //размер таблицы
    int size;
    Node **m;
    //необходим для перестройки таблицы
    Node **m2;
    HashFunc *function;

};

