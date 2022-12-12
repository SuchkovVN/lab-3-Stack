#include <iostream>
#include <string>
#include "Formula.h"
#include "Stack.h"
#include "Operations.h"
#include <math.h>

using namespace std;

bool TPostfix::BracketsCorrect(string& str) const
{
	TStack<bool> stack(16); // Стек для проверки наличия '('

	for (int i = 0; i < str.length(); i++)
	{
    char elem = str[i];
		if (elem == '(')
		{
			stack.Push(true);
		}
		else if (elem == ')')
		{
			if (stack.IsEmpty()) // Если стек пуст, то нет пары для ')' -> ошибка
				return false;
			stack.Pop();
		}
	}
	if (!stack.IsEmpty()) // Если стек не пуст, то слишком мало ')' -> ошибка
		return false;
	return true;
}

void TPostfix::ToInfix(string& str)
{
	string elem;
	Operations op;
	for (int i = 0; i < str.size();)
	{
		string tmp;
		elem = str[i];
		
		if (op.IsOperation(elem))
		{
			tmp = elem;
			i++;
		}
		else
		{
			while (!op.IsOperation(elem) && i < str.size())
			{
				if (elem != " ")
					tmp += elem;
				elem = str[++i];
			}
		}
		
		if ((tmp == "-") && (infix.size() == 0 || (infix.size() > 0 && infix[infix.size()-1] == "("))) // Превращение унарного минуса в бинарный
			infix.push_back("0");
		
		if (tmp.find_first_of("0123456789") == 0 && tmp.find_first_not_of("0123456789.") != string::npos) // Проверка на корректность имени переменной, если это переменная
		{
			string exc = "Invalid format of variable: " + tmp;
			throw exc;
		}

		if (tmp.size() != 0)
			infix.push_back(tmp);
	}
}

void TPostfix::ToPostfix()
{
	Operations op;
	TStack<string> opstack;

	for (int i = 0; i < infix.size(); i++)
	{
		string tmp = infix[i];
		if (!op.IsOperation(tmp))
		{
			postfix.push_back(tmp);
			continue;
		}
		else
		{
			if (tmp == "(")
			{
				opstack.Push(tmp);
				continue;
			}
			
			if (tmp == ")")
			{
				while (opstack.Top() != "(")
					postfix.push_back(opstack.Pop());
				opstack.Pop();
				continue;
			}
			
			while (!opstack.IsEmpty() && op.GetPriority(opstack.Top()) >= op.GetPriority(tmp))
				postfix.push_back(opstack.Pop());
			
			if (opstack.IsEmpty())
			{
				opstack.Push(tmp);
				continue;
			}
			else
			{
				if (op.GetPriority(opstack.Top()) < op.GetPriority(tmp)) 
				{
					opstack.Push(tmp);
					continue;
				}
			}
		}
	}
	while (!opstack.IsEmpty())
		postfix.push_back(opstack.Pop());
}

vector<string> TPostfix::GetVecOfVariables() const
{
	Operations op;
	vector<string> tmp;
	for (const string& elem : postfix)
	{
		if (elem.find_first_not_of("0123456789") == 0 && !op.IsOperation(elem))
		{
			int different = 0;
			for (const string& element : tmp) // Если tmp.size() == 0, то не произойдёт ни одной итерации и останется different == 0 -> добавится первый элемент
				if (element != elem)
					different++;
			if (different == tmp.size())
				tmp.push_back(elem);
		}
	}
	return tmp;
}

double TPostfix::Calculate(bool interface, vector<double> vecofvalues) const 
{
	map<string, double> values;
	vector<string> variables = GetVecOfVariables();
	if (interface)
	{
		if (variables.size() > 0)
		{
			cout << "\nEnter the values of the undefined variables:\n";
			for (string& elem : variables)
			{
				double value;
				cout << "\t" << elem << " = ";
				cin >> value;
				values.emplace(elem, value);
			}
		}
	}
	else
	{
		if (variables.size() != vecofvalues.size())
			throw string("Arrays of names and values have different sizes");
		for (int i = 0; i < variables.size(); i++)
			values.emplace(variables[i], vecofvalues[i]);
	}

	double res = 0;
	TStack<double> arguments;
	Operations op;
	for (const string& elem : postfix)
	{
		if (!op.IsOperation(elem))
		{
			if (find(variables.begin(), variables.end(), elem) != variables.end()) // Если elem - переменная
				arguments.Push(values[elem]);
			else
				arguments.Push(stod(elem));
		}
		else
		{
			if (op.GetArity(elem) == 1)
				arguments.Push(op.Calc(elem, arguments.Pop())); // Передаём для вычисления последнее значение
			else // if (op.GetArity(elem) == 2), т.к. в postfix нет скобок
				arguments.Push(op.Calc(elem, arguments.Pop(), arguments.Pop())); // Передаём для вычисления последние два значения
		}
	}
	res = arguments.Pop(); // Последний элемент в стеке - ответ
	return res;
}