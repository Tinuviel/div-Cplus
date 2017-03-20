#include "stdafx.h"
#include <iostream>


/**
  * Binary search in two different ways, both recursive and iterative to highlight the 
  * possibilities, diffrences and that they sometimes look almost the same.
  *	Lovisa Colérus 
  * testcode from http://www.learncpp.com/cpp-tutorial/7-x-chapter-7-comprehensive-quiz/
  * 2017-03-20
  */

//Iterative version
int binarySearchIter(int *array, int target, int min, int max)
{
	while (min <= max)
	{
		int middle = min + ((max - min) / 2);
		
		if (array[middle] > target)
			max = middle-1;	
		else if (array[middle] < target)
			min = middle + 1;
		else
			return middle;
	}
	return -1;
	
}

//Recursive verison
int binarySearchRec(int *array, int target, int min, int max)
{
	int middle = min + ((max - min) / 2);
	if (max < min)
		return -1;
	if (array[middle] > target)
		return binarySearchRec(array, target, min, middle - 1);
	else if (array[middle] < target)
		return binarySearchRec(array, target, middle + 1, max);
	else
		return middle;

		
}

//Test code
int main()
{
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
	const int numTestValues = 9;
	int testValues[numTestValues]  = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	for (int iii = 0; iii < numTestValues; ++iii)
	{
		int index = binarySearchRec(array, testValues[iii], 0, 14);
		if (index == expectedValues[iii])
			std::cout << "Test value " << testValues[iii] << " passed!\n";
		else
			std::cout << "Test value " << testValues[iii] << "failed. There is something wrong with your code!\n";
	}
	return 0;
}