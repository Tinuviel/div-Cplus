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
  *
  * Makes a deck of cards and can shuffle them. 
  * Optional to play a game of BlackJack
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
Card dealCard(std::array<Card, 52> &deck, Card *topOfDeck)
{
	return *topOfDeck;
}

/* Calculates the sum of the player or dealers cards. Maximum 9 cards since 4 TWO, 
   4 THREE and 1 FOUR is the way to get just over 21 with the max amount of cards
   If the sum is more than 21 we count the aces as 1 until the sum is 21 or lower */
int playerSum(std::array<Card, 9> &playerDeck)
{
	int sum = 0;
	int aceCount = 0;
	for (auto &card : playerDeck)
	{
		if (card.rank == Cardrank::RANK_ACE)
			++aceCount;
		 sum += getCardValue(card);
	}
	while ((sum > 21) && aceCount > 0)
	{
		sum = sum - 10;
		--aceCount;
	}

	return sum;
}


/* Initializes the starting conditions, */
Card* startGame(std::array<Card, 52> &deck, std::array<Card, 9> &playerDeck, std::array<Card, 9> &dealerDeck)
{
	Card *topOfDeck = &deck[0];
	dealerDeck[0] = dealCard(deck, topOfDeck);
	topOfDeck+=1;
	playerDeck[0] = dealCard(deck, topOfDeck);
	topOfDeck+=1;
	playerDeck[1] = dealCard(deck, topOfDeck);
	topOfDeck+=1;
	return topOfDeck;

}

/* Plays a game of blackjack, returns true if the player won */
bool playBlackJack(std::array<Card, 52> &deck)
{
	std::array<Card, 9> playerDeck;
	std::array<Card, 9> dealerDeck;
	Card *topOfDeck = startGame(deck, playerDeck, dealerDeck);
	int playerCardNr = 2;
	int dealerCardNr = 1;
	bool dealerDraw = true;
	std::cout << "Welcome to BlackJack, your sum is: " << playerSum(playerDeck) << '\n';
	std::cout << "The dealers sum is: " << playerSum(dealerDeck) << '\n';
	bool playerStand = false;
	while (true)
	{
		//While the player has not chosen stand yet 
		if (!playerStand)																	//if1 as long as the player haven't chosen stand yet
		{
			if (hitOrStand())																//if2 asks the player Hit or Stand
			{
				playerDeck[playerCardNr] = dealCard(deck, topOfDeck);
				topOfDeck += 1;
				++playerCardNr;

				if (playerSum(playerDeck) > 21)												//if3 Checks if the player lost because of the new card
				{
					std::cout << "Your sum is " << playerSum(playerDeck) << " and that is bigger than 21 so you lost\n";
					return false;
				}
				else
					std::cout << "Your sum is: " << playerSum(playerDeck) << '\n';
			}
			else																			//player chooses stand, which means they draw no new cards
			{
				playerStand = true;
				std::cout << "Your sum is still: " << playerSum(playerDeck) << '\n';
			}
		}
		if(dealerDraw)																		//if5 Dealer draws cards while its sums isn't greater than or eq to 17
		{
			dealerDeck[dealerCardNr] = dealCard(deck, topOfDeck);
			topOfDeck += 1;
			++dealerCardNr;
			std::cout << "The dealer has the sum: " << playerSum(dealerDeck) << '\n';
			if (playerSum(dealerDeck) > 21)													//if6 Checks if dealer looses
			{
				std::cout << "...and he lost\n";
				return true;
			}
			else if (playerSum(dealerDeck) >= 17)											//Or if the dealer should stop drawing cards
			{
				dealerDraw = false;
			}
		}
		if (playerStand && !dealerDraw)														//if7 Checks if both player and dealer has stopped drawing cards
		{
			if (playerSum(playerDeck) > playerSum(dealerDeck))								//if8 Check who won
			{
				std::cout << "You won!\n";
				return true;
			}
			else
			{
				std::cout << "You lost!\n";
				return false;
			}
		}
	}
}


int main()
{
	std::array<Card, 52> deck;
	makeDeck(deck);
	shuffleDeck(deck);
	bool win = playBlackJack(deck);
	return 0;
}