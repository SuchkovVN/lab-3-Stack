#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

#include <string>

const int MaxStackSize = 100;

template <class TType>
class TStack
{
private:
    TType* pMem;
    int size;
    int top;
    TStack(const TStack&) = delete; // Запрет на копирование стека
    void operator=(const TStack&) = delete; // Запрет на присваивание стека

public:
    TStack(int _size = MaxStackSize) // Конструктор по умолчанию
    {
        size = _size;
        top = -1;
        if ((size < 1) || (size > MaxStackSize))
            throw std::string("Incorrect Stack Size");
        pMem = new TType[size];
    }
    
    ~TStack() // Деструктор
    {
        delete [] pMem;
    }

    bool IsEmpty() { return top == -1; } // Проверка пустой ли стек

    bool IsFull() { return top == size - 1; } // Проверка заполнен ли стек

    void Push(const TType obj) // Вставка элемента в вершину стека
    {
        if (IsFull())
            throw std::string("Stack Is Full");
        pMem[++top] = obj;
    }

    TType Pop() // Получение значения верхнего элемента с удалением
    {
        if (IsEmpty())
            throw std::string("Stack Is Emty");
        return pMem[top--];
    }

    TType Top() // Получение значения верхнего элемента без удаления // Top Of Stack
    {
        if (IsEmpty())
            throw std::string("Stack Is Emty");
        return pMem[top];
    }

};
