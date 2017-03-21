#include "stdafx.h"
#include <iostream>
#include <cassert>


/**
  * A class that behaves like a stack
  * Lovisa Colérus
  * 2017-03-21
  */
class Stack
{
private:
	int m_array[10];
	int m_sp;

public:
	//Sets the SP to 0 and all the elements in the stack to 0
	void reset()
	{
		for (auto &el : m_array)
			el = 0;
		m_sp = 0;
	}

	//pushes a value to the stack and increases the SP
	bool push(int value)
	{
		if (m_sp < 10)
		{
			m_array[m_sp] = value;
			++m_sp;
			return true;
		}
		else
			return false;
	}

	//asserts that there is elements on the stack, of there are it pops a value from the stack and decreases the SP
	int pop()
	{
		assert(m_sp >= 0);
		return m_array[--m_sp];
	}

	//Prints the stack from the element lowest in the stack
	void print()
	{
		std::cout << "( ";
		int stackpoint = 0;
		while (stackpoint < m_sp)
		{
			std::cout << m_array[stackpoint] << " ";
			++stackpoint;
		}
		std::cout << ")\n";
	}


};

//Testing
int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}