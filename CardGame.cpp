#include "stdafx.h"
#include <iostream>
#include <array>
#include <time.h> 
#include <string>
#include "CardGame.h"
#include <algorithm>
/** Lets make a card game
  * @author Lovisa Colérus
  * 2017-02-23 v1
  */





//Prints a card using two chars
void printCard(const Card &card)
{
	char suit;
	char rank;
	switch (card.suit)
	{
		case Cardsuit::SUIT_CLUBS:		suit = 'C';		break;
		case Cardsuit::SUIT_DIAMONDS:	suit = 'D';		break;
		case Cardsuit::SUIT_HEARTS:		suit = 'H';		break;
		case Cardsuit::SUIT_SPADES:		suit = 'S';		break;
		default:						suit = '\0';
	}

	switch (card.rank)
	{
		case Cardrank::RANK_TWO:	rank = '2';		break;
		case Cardrank::RANK_THREE:	rank = '3';		break;
		case Cardrank::RANK_FOUR:	rank = '4';		break;
		case Cardrank::RANK_FIVE:	rank = '5';		break;
		case Cardrank::RANK_SIX:	rank = '6';		break;
		case Cardrank::RANK_SEVEN:	rank = '7';		break;
		case Cardrank::RANK_EIGHT:	rank = '8';		break;
		case Cardrank::RANK_NINE:	rank = '9';		break;
		case Cardrank::RANK_TEN:	rank = 'T';		break;
		case Cardrank::RANK_JACK:	rank = 'J';		break;
		case Cardrank::RANK_QUEEN:	rank = 'Q';		break;
		case Cardrank::RANK_KING:	rank = 'K';		break;
		case Cardrank::RANK_ACE:	rank = 'A';		break;
		default:					rank = '\0';

	}
	std::cout << rank << suit;
		
}

//prints every card in the deck
void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

//Initializes the array that holds all the cards in the deck
void makeDeck(std::array<Card, 52> &deck)
{
	
	int cardNumber = 0;
	for (int suit = SUIT_CLUBS; suit != Cardsuit::MAX_SUITS; ++suit)
	for (int rank = Cardrank::RANK_TWO; rank != Cardrank::MAX_RANKS; ++rank)
	{
		deck[cardNumber].rank = static_cast<Cardrank>(rank);
		deck[cardNumber].suit = static_cast<Cardsuit>(suit);
		cardNumber++;
	}
	
	
}

//Swaps two cards
void swapCards(Card &card1, Card &card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

//shuffels the deck
void shuffleDeck(std::array<Card, 52> &deck) 
{
	srand(time(NULL));
	rand();
	for (auto &card : deck)
	{
		int randomCard = rand() % 52;
		std::cout << randomCard;
		swapCards(card, deck[randomCard]);
	}
}

//returns the value of the card
int getCardValue(Card card)
{
	switch (card.rank)
	{
		case Cardrank::RANK_TWO:	return 2;
		case Cardrank::RANK_THREE:	return 3;
		case Cardrank::RANK_FOUR:	return 4;
		case Cardrank::RANK_FIVE:	return 5;
		case Cardrank::RANK_SIX:	return 6;
		case Cardrank::RANK_SEVEN:	return 7;
		case Cardrank::RANK_EIGHT:	return 8;
		case Cardrank::RANK_NINE:	return 9;
		case Cardrank::RANK_TEN:		
		case Cardrank::RANK_JACK:			
		case Cardrank::RANK_QUEEN:		
		case Cardrank::RANK_KING:	
			return 10;
		case Cardrank::RANK_ACE:	return 11;
		default:					return 0;
	}
}


/*	Asks the user if it wants another card ( Hit ) or if it wants to end its turn ( Stand ) */
bool hitOrStand()
{
	std::string answer;
	std::cout << "Hit or Stand?: ";
	while (true) {
		std::cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

		if (answer == "hit")
		{
			return true;
		}
		else if (answer == "stand")
		{
			return false;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid expression, please enter Hit or Stand: ";
		}
		
	}

}

//Deals a card from the 'top' of the deck
Card dealCard(std::array<Card, 52> &deck, int topOfDeck)
{
	return deck[topOfDeck];
}

/* Calculates the sum of the player or dealers cards. Maximum 9 cards since 4 TWO, 
   4 THREE and 1 FOUR is the way to get just over 21 with the max amount of cards*/
int playerSum(std::array<Card, 9> &playerDeck)
{
	int sum = 0;
	for (auto &card : playerDeck)
	{
		sum += getCardValue(card);
	}
	return sum;
}


/* Initializes the starting conditions, */
int startGame(std::array<Card, 52> &deck, std::array<Card, 9> &playerDeck, std::array<Card, 9> &dealerDeck)
{
	int topOfDeck = 0;
	dealerDeck[0] = dealCard(deck, topOfDeck);
	++topOfDeck;
	playerDeck[0] = dealCard(deck, topOfDeck);
	++topOfDeck;
	playerDeck[1] = dealCard(deck, topOfDeck);
	++topOfDeck;
	return topOfDeck;

}



int main()
{
	std::array<Card, 52> deck;
	std::array<Card, 9> playerDeck;
	std::array<Card, 9> dealerDeck;
	makeDeck(deck);
	shuffleDeck(deck);
	int topOfDeck = startGame(deck, playerDeck, dealerDeck);
	int playerCardNr = 2;
	int dealerCardNr = 1;
	while (true)
	{
		std::cout << "Your sum is: " << playerSum(playerDeck) << '\n';
		if (playerSum(playerDeck) > 21)
		{
			std::cout << "Your sum is now: " << playerSum(playerDeck) << " and you lost\n";
			break;
		}


		if (hitOrStand())
		{
			playerDeck[playerCardNr] = dealCard(deck, topOfDeck);
			++topOfDeck;
			++playerCardNr;
			std::cout << "Your sum is: " << playerSum(playerDeck) << '\n';
		}
		else
		{
			std::cout << "Your sum is: " << playerSum(playerDeck) << '\n';
		}

		dealerDeck[dealerCardNr] = dealCard(deck, topOfDeck);
		++topOfDeck;
		++dealerCardNr;
		std::cout << "The dealer has the sum: " << playerSum(dealerDeck) << '\n';
		if (playerSum(dealerDeck) > 17)
		{
			std::cout << "...and he lost\n";
			break;
		}

	}
	return 0;
}