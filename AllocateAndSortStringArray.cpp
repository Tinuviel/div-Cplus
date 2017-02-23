#include "stdafx.h"
#include <iostream>
#include <utility>
#include <string>



/**
  * @author Lovisa Colérus
  * 2017-02-23
  * Dynamically allocating an array and lets the user initialize it with strings
  * Sorts the strings and prints the sorted namelist
  */



//Asks User for the length of the array
int askUser()
{
	int nrNames;
	std::cout << "How many names do you wish to enter? ";
	while (true) {
		std::cin >> nrNames;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nInvalid input, please enter a number: ";
		}
		else 
		{
			return nrNames;
		}
	}	
}


//Makes the user initialize the array with names. Names can include numbers etc
std::string* initialize(int nrNames)
{
	std::string *nameArray = new std::string[nrNames];

	for (int i = 0; i < nrNames; ++i)
	{
		std::cout << "Enter name #" << i+1 <<": ";
		std::cin >> nameArray[i];
	}

	return nameArray;
}

//Sorts the array alphabetically/numerically with bubblesort
void bubbleSort(std::string array[], int arrayLength)
{
	do
	{
		for (int iii = 0; iii < arrayLength - 1; ++iii)
		{
			if (array[iii] > array[iii + 1])
			{
				std::swap(array[iii], array[iii + 1]);
			}
		}
		--arrayLength;
	} while (arrayLength > 0);
}


//prints the array
void printArray(std::string *ptr, int arrayLength)
{
	for (int j = 0; j < arrayLength; ++j)
	{
		std::cout << "Name #" << j+1 << " is: " << *(ptr+j) <<'\n';
	}
}

int main()
{

	int nrNames = askUser();
	std::string *names = initialize(nrNames);
	bubbleSort(names, nrNames);
	printArray(names, nrNames);
	delete[] names; //deallocates the memory
	names = nullptr; //set the pointer to null to avoid problems
	return 0;
}
