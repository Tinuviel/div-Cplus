#include "stdafx.h"
#include <iostream>
#include "Constants.h"

double distFallen(int x_sec) {
	return myConstants::gravity*x_sec*x_sec / 2;
}

//Calculates the heigth of the falling ball
double ballHeight(double heightOfTower, int x_sec) {
	double height = heightOfTower - distFallen(x_sec);
	if (height > 0) {
		return height;
	}
	else {
		return 0;
	}
}


//Prints the position of the ball at every second until the ball is on the ground
void printBallFalling(double heightOfTower) {
	double heightOfBall = heightOfTower;
	int time = 0;
	 do{
		heightOfBall = ballHeight(heightOfTower, time);
		std::cout << "At " << time << "seconds, the ball is at height " << heightOfBall << std::endl;
		++time;
		
	 } while (heightOfBall > 0);
}


//Asks the user for the heigth of the tower
//Checks if the user inputs a valid number and only allows towers up to 2 km in height because of physics
double askForHeight() {

	while (true) 
	{
		std::cout << "How high is the tower? " << std::endl;
		double height;
		std::cin >> height;
		if (height >= 2000)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "the tower can't resonably be that high\n";
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "invalid input, try again\n";

		}
		else
		{
			std::cin.ignore(32767, '\n');
			return height;
		}
	}
	
}



int main()
{
	double height = askForHeight();
	printBallFalling(height);
}