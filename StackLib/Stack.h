#pragma once
#include <cstddef>

using namespace std;

template<typename T>
class TStack 
{
protected:
  T* pMem; //Элементы хранятся здесь 
  size_t sz; //Размер массива 
  size_t dataCount; //Кол-во элементов в стеке 
  size_t topIndx; //Индекс вершины стека 
public:
  TStack(size_t size = 1);
  TStack(T* Mem, size_t size);
  TStack(const TStack<T>& stack);
  ~TStack();

  bool IsEmpty() const; //Проверка на пустоту 
  bool IsFull() const; //Проверка на заполненость 
  void Push(const T& elem); //Добавить элемент 
  T Top() const; //Узнать верхний элемент 
  T Pop(); //Извлечь верхний элемент 
  

};

template<typename T>
TStack<T>::TStack(size_t size) 
{
  sz = size;
  pMem = new T[sz];
  dataCount = 0;
  topIndx = 0;
}

template<typename T>
TStack<T>::TStack(T* Mem, size_t size)
{
  if (size <= 0) throw "Error: invalid stack size";
  if (Mem == 0) throw "Error: invalid stack mem";
  sz = size; 
  pMem = new T[sz];
  copy(Mem, Mem + sz, pMem);
  dataCount = size;
  topIndx = size - 1;
}

template<typename T>
TStack<T>::TStack(const TStack<T>& stack)
{

}