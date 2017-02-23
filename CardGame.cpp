#include "stdafx.h"
#include <iostream>
#include <array>

/** Lets make a card game
  * @author Lovisa Colérus
  * 2017-02-23 v1
  */

enum Cardsuit
{
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES,
	MAX_SUITS
};

enum Cardrank
{
	RANK_TWO,
	RANK_THREE,
	RANK_FOUR,
	RANK_FIVE,
	RANK_SIX,
	RANK_SEVEN,
	RANK_EIGHT,
	RANK_NINE,
	RANK_TEN,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

//A playing card
struct Card
{
	Cardsuit suit;
	Cardrank rank;
};

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

int main()
{
	std::array<Card, 52> deck;
	makeDeck(deck);
	printDeck(deck);
	return 0;
}