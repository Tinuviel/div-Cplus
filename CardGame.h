#pragma once


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

void printCard(const Card &card);
void printDeck(const std::array<Card, 52> &deck);
void makeDeck(std::array<Card, 52> &deck);
void swapCards(Card &card1, Card &card2);
void shuffleDeck(std::array<Card, 52> &deck);
int getCardValue(Card card);
bool hitOrStand();
Card dealCard(std::array<Card, 52> &deck, int topOfDeck);
int playerSum(std::array<Card, 9> &playerDeck);
int startGame(std::array<Card, 52> &deck, std::array<Card, 9> &playerDeck, std::array<Card, 9> &dealerDeck);

