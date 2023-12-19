#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  size_t sz;
  int top;
public:
  TStack(size_t _size):sz(_size)
  {
    top = -1;
    if ((sz < 1) || (sz > MaxStackSize))
      throw out_of_range("stack size should be greater than zero");
    pMem = new T[sz];
  }
  TStack(const TStack& s):sz(s.sz),top(s.top) //конструктор копирования
  {
      pMem = new T[sz];
      for (int i = 0; i < sz; i++)
          pMem[i] = s.pMem[i];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  size_t size()
  {
      return sz;
  }
  bool IsEmpty()
  {
      return top == -1;
  }
  bool IsFull()
  {
      return top == sz - 1;
  }
  T Pop()
  {
      top--;
      return pMem[top+1];
  }
  T ViewTop()
  {
      return pMem[top];
  }
  void Push(const T& val)
  {
      top++;
      pMem[top] = val;
  }
  TStack& operator=(const TStack& s)
  {
      if (*this != s)
      {
          sz = s.sz;
          top = s.top;
          delete[] pMem;
          pMem = new T[sz];
          for (int i = 0; i < sz; i++) {
              pMem[i] = s.pMem[i];
          }
      }
      return *this;
  }
  bool operator==(const TStack& s) const
  {
      if (sz == s.sz && top == s.top)
          for (int i = 0; i < sz; i++)
              if (pMem[i] != s.pMem[i])
                  return false;
      if (sz != s.sz || top != s.top)
          return false;
      return true;
  }
  bool operator!=(const TStack& s) const
  {
      return!(s == *this);
  }
};

#endif
