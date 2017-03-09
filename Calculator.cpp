#include "stdafx.h"
#include <iostream>
#include "Calculator.h"

/**
  * Lovisa Colérus  
  * 2017-03-09
  * Excercise in functionpointers and a bit struct
  * takes two ints and a mathematical op from the user
  * Prints the answer
  * All functions are basic
  */

struct arithmeticStruct
{
	char mathOp;
	arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[] = {
	{'+', add},
	{'-', subtract},
	{'*', multiply},
	{'/', divide}
};

arithmeticFcn getArithmeticFunction(char op)
{
	for (auto &a : arithmeticArray)
	{
		if (a.mathOp == op)
			return a.fcn;
	}				
}

int askUserForInteger()
{
	int x;
	while (true)
	{

		std::cout << "Enter an integer: ";
		std::cin >> x;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again\n";
		}
		else
			return x;
	}
}

char askUserForOperator()
{
	char op;
	while (true)
	{
		std::cout << "Enter an operator (+, -, *, /): ";
		std::cin >> op;
		if (op == '+' || op == '-' || op == '/' || op == '*')
		{
			return op;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again\n";
		}
	}
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x*y;
}

int divide(int x, int y)
{
	return x / y;
}

int main()
{
	int x = askUserForInteger();
	int y = askUserForInteger();
	char op = askUserForOperator();
	arithmeticFcn fcn = getArithmeticFunction(op);
	std::cout << x << " " << op << " " << y << " = " << fcn(x, y) << '\n';

	return 0;
}