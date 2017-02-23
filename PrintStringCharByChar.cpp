#include "stdafx.h"
#include <iostream>
#include <string>

/** Two ways to print a string char by char
  * @author Lovisa Colérus
  * 2017-02-23
  */

//Prints a std::string by using a for each-loop
void printStdStringByChar_ForEach(std::string string)
{
	for (auto &ch : string)
	{
		std::cout << ch << " ";
	}
	std::cout << '\n';
}

//Print a C-style string char by char by using a pointer
void printStringByChar_Pointer(char *string)
{
	while (true)
	{
		if (*string == '\0')
			break;
		std::cout << *string << " ";
		++string;
	}
	std::cout << '\n';
}


int main()
{
	std::string helloworld = "Hello world!";
	char chelloworld[] = "Hello world!";
	printStdStringByChar_ForEach(helloworld);
	printStringByChar_Pointer(chelloworld);
	return 0;
}