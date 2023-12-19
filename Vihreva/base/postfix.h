#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <regex>
#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
public:
  TPostfix()
  {
    infix = "";
    postfix = "";
  }
  TPostfix(string s)
  {
      for (int i = 0; i < s.length()-1; i++)
      {
          if (s[i] == '/' && s[i + 1] == '0')
              throw "you can not divide on zero";
      }
      infix = s;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
