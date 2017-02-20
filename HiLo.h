#pragma once

/**
*	@author Lovisa Colérus
*  2017-02-20
* Headerfile and constants for HiLo
* A game of guessing which random number the computer thinks of
*/
namespace constants
{
	const int min = 1;
	const int max = 100;
	const int numberOfGuesses = 7;
}

int askForGuess(int min, int max);

int generateNumber(int min, int max);

bool compareGuessToAnswer(int guess, int answer);

void playAgain();

void playGame();

void testRandomNumber();

