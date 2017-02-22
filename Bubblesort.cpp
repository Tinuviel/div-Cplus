#include "stdafx.h"
#include <iostream>
#include <utility>

/**
  *@author Lovisa Colérus
  * 2017-02-22
  * a bubblesort-algorithm
  */


/** Sorts an array by comparing the indexes next to eachother and swapping their indexes if the first is bigger than the second
  * Prints how many iterations it had to go through
  */
void bubbleSort(int array[], int arrayLength)
{
	int iteration = 0;
	do
	{
		++iteration;
		bool swapped = false;
		for (int iii = 0; iii < arrayLength - 1; ++iii)
		{
			if (array[iii] > array[iii + 1])
			{
				std::swap(array[iii], array[iii + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			std::cout << "Ended on iteration: " << iteration << '\n';
			break;
		}
			
		--arrayLength;
	} while (arrayLength > 0);
	
}


// Prints an array
void printArray(int array[], int arrayLength)
{
	for (int jjj = 0; jjj < arrayLength; ++jjj)
	{
		std::cout << array[jjj] << " ";
	}
	std::cout << '\n';
}

int main()
{
	const int length(9);
	int array[length] = { 6, 8, 2, 9, 7, 1, 5, 4, 3 };
	int array2[4]{ 1,2,3,4 };

	const int arrayLength = sizeof(array) / sizeof(array[0]);
	const int array2Length = sizeof(array2) / sizeof(array2[0]);
	printArray(array, arrayLength);
	bubbleSort(array, arrayLength);
	printArray(array, arrayLength);

	printArray(array2, array2Length);
	bubbleSort(array2, array2Length);
	printArray(array2, array2Length);

	return 0;
}

