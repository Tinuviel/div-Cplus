#include "stdafx.h"
#include <iostream>
#include <string>

/**
* A monsterclass that creates a monster and prints the monsters info
* @author Lovisa Colerus
* 2017-02-17
*/

enum MonsterClass
{
	OGRE,
	SLIME,
	DRAGON,
	GIANT_SPIDER,
	BUTTERFLY
};

struct Monster
{
	std::string monsterName;
	MonsterClass monsterClass;
	int health;
};


//converts the monsterclass to a printable string
std::string enumToString(MonsterClass monsterClass)
{
	switch (monsterClass) 
	{
		case OGRE: return "Ogre";
		case SLIME: return "Slime";
		case DRAGON: return "Dragon";
		case GIANT_SPIDER: return "Giant Spider";
		case BUTTERFLY: return "Butterfly";
		default: return "Not valid class";
	}
}


void printMonster(Monster monster)
{
	std::string monsterClass = enumToString(monster.monsterClass);
	std::cout << "This " << monsterClass << " is named " << monster.monsterName << " and has " << monster.health << " health" << std::endl;
}

int main() {
	Monster m1{ "Torvald", OGRE, 150 };
	Monster m2{ "Bert", DRAGON, 2000 };
	Monster m3{ "Aragog", GIANT_SPIDER, 2 };
	printMonster(m1);
	return 0;
}