#pragma once

/**
  * template class Vector
  *
  *@ T - тип координат вектора
  *@ param SIZE - размер вектора
  */
template <typename T, int SIZE>
class Vector
{
public:
    /// зануляет вектор
    Vector()
    {
        for (int i = 0; i < SIZE; i++)
            m[i] = 0;
    }
    /**
      *считает сумму векторов
      *@ param a - указатель на первый вектор
      *@ param b - указатель на второй вектор
      */
    void sum(Vector<T, SIZE> *a, Vector<T, SIZE> *b)
    {
        for (int i = 0; i < SIZE; i++)
            m[i] = a->m[i] + b->m[i];
    }
    /**
      *считает разность векторов
      *@ param a - указатель на первый вектор
      *@ param b - указатель на второй вектор
      */
    void sub(Vector<T, SIZE> *a, Vector<T, SIZE> *b)
    {
        for (int i = 0; i < SIZE; i++)
            m[i] = a->m[i] - b->m[i];
    }
    /**
      *возвращает значение скалярного произведения векторов
      *@ param a - указатель на первый вектор
      *@ param b - указатель на второй вектор
      */
    T mult(Vector<T, SIZE> *a, Vector<T, SIZE> *b)
    {
        T result = 0;
        for (int i = 0; i < SIZE; i++)
            result = result + a->m[i] * b->m[i];
        return result;
    }
    /// проверяет на нулевой вектор
    bool null()
    {
        for (int i = 0; i < SIZE; i++)
            if (m[i] != 0)
                return false;
        return true;
    }
    /**
      *копирует вектор
      *@ param a - указатель на вектор, в который происходит копирование
      */
    void copy(Vector<T, SIZE> *a)
    {
        for (int i = 0; i < SIZE; i++)
            a->m[i] = m[i];
    }

    T m[SIZE];
};

