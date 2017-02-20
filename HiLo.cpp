#include "stdafx.h"
#include <iostream>
#include "HiLo.h"
#include <random>

/**
 *	@author Lovisa Colérus
 *  2017-02-20
 * A game of guessing which random number the computer thinks of
 */


//Generates a random number 
int generateNumber(int min, int max)
{
	int discard = rand(); //discards the first since Visual Studio doesnt give a good first random number
	int use = rand() % max + min;
	return use;
}


//Compares the users guess to the answer, if the user guess right it returns false to get out of the guessing loop and starts a new game
//if the user wants to play again. Otherwise it terminates the program.
//Returns true if the guess is wrong => it means we should continue to ask the user
bool compareGuessToAnswer(int guess, int answer)
{
	if (guess == answer)
	{
		std::cout << "You won! Do you want to play again? y/n \n";
		playAgain();
		return false;
	}
	else if (guess > answer)
	{
		std::cout << "Your guess is too high" << std::endl;
		return true;
	}
	else if (guess < answer)
	{
		std::cout << "Your guess is too low" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Something unexpected happened" << std::endl;
		exit(0);
	}
}

//Asks the user if they want to play another time
void playAgain()
{
	char answer;
	
	while (true)
	{
		std::cin >> answer;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again y/n\n";
		}
		else if(answer == 'y') 
		{
			std::cin.ignore(32767, '\n');
			break;
		}
		else if (answer == 'n')
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Goodbye!\n";
			exit(0);
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again y/n\n";
		}
	}
}

//Asks the user to guess, only accepts int in the range
int askForGuess(int min, int max)
{
	int guess = 0;
	while(true)
	{
		std::cout << "Enter a guess: ";
		std::cin >> guess;
		if ((guess < min) || (guess > max) )
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Your guess is out of range! Try again\n";
		}
		else if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return guess;
		}
	}
}


//Gives the logic for playing the game one or several times
void playGame()
{
	bool play = true;
	while (play) 
	{
		std::cout << "I'm thinking of a number between " << constants::min << " and " << constants::max << std::endl;
		int guess = 0;
		int answer = generateNumber(constants::min, constants::max);

		for (int iii = 0; iii < constants::numberOfGuesses; iii++)
		{
			guess = askForGuess(constants::min, constants::max);
			compareGuessToAnswer(guess, answer);
		} 
		std::cout << "You lost! Play Again? y/n: ";
		playAgain();
	}
}
int main()
{
	playGame();
	return 0;
}

void testRandomNumber()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << generateNumber(constants::min, constants::max) << "\n";
	}

}