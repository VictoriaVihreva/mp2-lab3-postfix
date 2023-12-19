#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;

  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  cin >> expression;
  TPostfix post(expression);
  cout << "\nАрифметическое выражение: " << post.GetInfix() << "\n" << endl;
  post.ToPostfix();
  cout << "\nПостфиксная форма: " << post.GetPostfix() << endl;
  res = post.Calculate();
  cout << expression << " = " << res << endl;
  return 0;
}
