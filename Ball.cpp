#include "stdafx.h"
#include <iostream>
#include <string>

/**
  * A class to test out constructors, might extend later
  * Lovisa Colérus
  * 2017-03-22
  */
class Ball
{
private:
	std::string m_color;
	double m_radius;

public:

	Ball(double radius)
	{
		m_color = "Black";
		m_radius = radius;
	}

	Ball(std::string color = "Black", double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}


	void print()
	{
		std::cout << "The ball is " << m_color << " and has a radius of " << m_radius << '\n';
	}
};

//Testcode
int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	return 0;
}