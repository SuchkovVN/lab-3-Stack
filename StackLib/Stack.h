#pragma once
#include <cstddef>

using namespace std;

template<typename T>
class TStack 
{
protected:
  T* pMem; //Элементы хранятся здесь 
  size_t sz; //Размер массива 
  long int topIndx; //Индекс вершины стека 
public:
  TStack(size_t size = 1);
  TStack(T* Mem, size_t size);
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
  topIndx = -1;
}

template<typename T>
TStack<T>::TStack(T* Mem, size_t size)
{
  if (size <= 0) throw "Error: invalid stack size";
  if (Mem == 0) throw "Error: invalid stack mem";
  sz = size; 
  pMem = new T[sz];
  copy(Mem, Mem + sz, pMem);
  topIndx = size - 1;
}

template<typename T> 
TStack<T>::~TStack()
{
<<<<<<< HEAD
  delete [] pMem;
  pMem = 0;
}

template<typename T>
bool TStack<T>::IsEmpty() const
{
  if (topIndx == -1) return true;
  return false;
}

template<typename T>
bool TStack<T>::IsFull() const
{
  if (topIndx == sz - 1) return true;
  return false;
}

template<typename T>
void TStack<T>::Push(const T& elem)
{
  if (topIndx == sz - 1) throw "Error: stack is full";
  topIndx++;
  pMem[topIndx] = T;
}

template<typename T>
T TStack<T>::Pop()
{
  if (topIndx == -1) throw "Error: stack is empty";
  T temp = pMem[topIndx];
  topIndx--;
  return temp;
}

template<typename T>
T TStack<T>::Top() const
{
  if (topIndx == -1) throw "Error: stack is empty";
  T temp = pMem[topIndx];
  return temp;
}
=======
  sz = stack.sz;
  pMem = new T[sz];
  copy(stack.pMem, stack.pMem + sz, pMem);
  dataCount = stack.dataCount;
  topIndx = stack.topIndx;
}

template<typename T>
TStack<T>::~TStack()
{
  delete [] pMem;
  pMem = 0;
}

template<typename T>
bool TStack<T>::IsEmpty() const 
{
  if (dataCount == 0) return true;
  else return false; 
}

template<typename T>
bool TStack<T>::IsFull() const 
{
  if (dataCount == sz) return true;
  else return false;
}

template<typename T>
void TStack<T>::Push(const T& elem)
{
  if (dataCount == sz) throw "Error: can't push"; 
  if (dataCount == 0)
  {
    topIndx = 0;
  }
  else topIndx++;

  pMem[topIndx] = elem;
  dataCount++;
}

template<typename T>
T TStack<T>::Pop()
{
  if (dataCount == 0) throw "Error: can't pop";
  T temp = pMem[topIndx];
  dataCount--;
  if (topIndx != 0) topIndx--;

  return temp;
}

template<typename T>
T TStack<T>::Top() const
{
  T temp = pMem[topIndx];
  return temp;
}

>>>>>>> be460bed2fc506bc8304f4a2b396f84db34ab6af
