#pragma once
namespace myConstants
{
	const double gravity = 9.8;
}

double distFallen(int x_sec);
double askForHeight();
void printBallFalling(double heightOfTower);
double ballHeight(double heightOfTower, int x_sec);