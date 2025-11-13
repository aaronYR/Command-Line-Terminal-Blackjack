#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <vector>
#include <iostream>
#include "Card.h"
using namespace std;

// Base class for player and dealer
class Participant {
protected:
	vector<Card> hand; // Cards in hand

public:
	void addCard(Card card);                // Add a card
	int getHandValue() const;               // Get total hand value
	void showHand(bool hideFirstCard = true) const; // Show cards
};

#endif
