#pragma once

/**
  * template class Sort
  *
  * T - тип объектов для сортировки
  * Compare - тип объекта, сравнивающего объекты сортировки
  */
template <typename T, typename Compare>
class Sort
{
public:
    /**
      * сортирует объекты методом пузырьковой сортировки
      * @param m - указатель на первый элемент массива объектов
      * @param SIZE - размер массива
      * @param CMP - объект, сравнивающий элементы массива, в нем должен быть реализован метод comp,
      *              принимающий два объекта и возвращающий число больше нуля, если второй "больше"
      */
    void BSort(T *m, int SIZE, Compare *CMP);
};


template <typename T, typename Compare>
void Sort<T, Compare>::BSort(T *m, int SIZE, Compare *CMP)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (CMP->comp(m[j], m[i]) > 0)
            {
                T k = m[i];
                m[i] = m[j];
                m[j] = k;
            }
        }

    }
}
