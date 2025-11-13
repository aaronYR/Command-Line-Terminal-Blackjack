#include "Deck.h"

// Constructor that builds a standard 52-card deck using vector function push_back
Deck::Deck() {
	const string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards.push_back(Card(ranks[j], suits[i]));
		}
	}
}

// Shuffles the deck using rand() and the Fisher-Yates shuffle algorithm
void Deck::shuffleDeck() {
	for (int i = cards.size() - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}

// Draws the top card
Card Deck::drawCard() {
	Card top = cards.back();
	cards.pop_back();
	return top;
}

// Check to see if the deck is empty
bool Deck::isEmpty() const {
	return cards.empty();
}
