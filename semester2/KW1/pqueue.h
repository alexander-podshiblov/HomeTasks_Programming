#include <stdio.h>
#pragma once

/**
@class PQueue
класс, реализующий очередь с приоритетами
*/

template <typename T>
class PQueue
{
public:
/// исключение
    class EmptyList {};
/// конструктор, инициализация полей
    PQueue()
    {
        head = new Node;
        head->next = NULL;
    }
/// деструктор, очистка памяти
    ~PQueue()
    {
        while (head->next != NULL)
        {
            Node *tmp = head->next;
            head->next = tmp->next;
            delete tmp;
        }
        delete head;
    }
/**
  *добавляет новый элемент в очередь
  *@param T - значение элемента очереди
  *@param priority - численный приоритет элемента
  */
    void enqueue(T value, int priority)
    {
        Node *tmp = head;
        while ((tmp->next != NULL) && (priority < tmp->next->priority))
            tmp = tmp->next;
        Node *tmp2 = new Node;
        tmp2->next = tmp->next;
        tmp2->value = value;
        tmp2->priority = priority;
        tmp->next = tmp2;
    }
/// возвращает значение элемента с максимальным приоритетом и удаляет его из очереди
    T dequeue()
    {
        if (head->next != NULL)
        {
            T k;
            Node *tmp = head->next;
            head->next = tmp->next;
            k = tmp->value;
            delete tmp;
            return k;
        }
        else
            throw EmptyList();
    }

private:
    struct Node
    {
        int priority;
        T value;
        Node *next;
    };

    Node *head;
};

