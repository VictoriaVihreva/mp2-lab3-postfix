#include "postfix.h"
#include "stack.h"


class op //класс оператора, содержащий сам оператор и его приоритет
{
public:
	char operate;
	int priority;
	op() :operate(' '), priority(-1) {}
	op(char oper,int pr): operate(oper), priority(pr){}
};

string TPostfix::ToPostfix()
{
	
	TStack<op> stack(infix.length());
	string numb = { "0123456789" };
	int type = -1;
	for (int i = 0; i < infix.length(); i++)
	{
		switch(infix[i])
		{
		case '(':
		{
			stack.Push(op('(',0));
			break;
		}
		case ')':
		{
			while (stack.ViewTop().operate != '(')
			{
				postfix = postfix + stack.Pop().operate;
			}
			stack.Pop();
			break;
		}
		case '+':
		{
			while (!(stack.IsEmpty())) 
			{
				if (stack.ViewTop().priority >= 1)
					postfix = postfix + stack.Pop().operate;
				else break;
			}
			stack.Push(op('+', 1));
			break;
		}
		case '-':
		{
			while (!(stack.IsEmpty()))
			{
				if (stack.ViewTop().priority >= 1)
					postfix = postfix + stack.Pop().operate;
				else break;
			}
			stack.Push(op('-', 1));
			break;
		}
		case '*':
		{
			while (!(stack.IsEmpty()))
			{
				if (stack.ViewTop().priority >= 2)
					postfix = postfix + stack.Pop().operate;
				else break;
			}
			stack.Push(op('*', 2));
			break;
		}
		case '/':
		{
			while (!(stack.IsEmpty()))
			{
				if (stack.ViewTop().priority >= 2)
					postfix = postfix + stack.Pop().operate;
				else break;
			}
			stack.Push(op('/', 2));
			break;
		}
		default:
		{
			int f = 1;
			for (int j = 0; j < 10; j++)
				if (infix[i] == numb[j])
				{
					postfix = postfix + infix[i];
					f = 0;
					break;
				}
			if (f) throw "incorrect simbol";
		}
		}
		
	}
	while (!(stack.IsEmpty()))
		postfix = postfix + stack.Pop().operate;
  return postfix;
}

double TPostfix::Calculate()
{
	TStack<double> stack(postfix.length());
	double res = 0;
	
	for (int i = 0; i < postfix.length(); i++)
	{
		switch (postfix[i])
		{
		case '+':
		{
			res = stack.Pop() + stack.Pop();
			stack.Push(res);
			break;
		}
		case '-':
		{
			res = -stack.Pop() + stack.Pop();
			stack.Push(res);
			break;
		}
		case '*':
		{
			res = stack.Pop() * stack.Pop();
			stack.Push(res);
			break;
		}
		case '/':
		{
			double divider = stack.Pop();
			res = stack.Pop()/divider;
			stack.Push(res);
			break;
		}
		default:
		{
			stack.Push(postfix[i] - '0');
			break;
		}
		}
	}
  return stack.Pop();
}