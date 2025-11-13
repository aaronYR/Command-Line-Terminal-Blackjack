#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include "Card.h"
using namespace std;

// Deck class for holding and managing cards
class Deck {
private:
    vector<Card> cards;  // List of cards

public:
    Deck();              // Makes a new deck
    void shuffleDeck();  // Shuffles the deck
    Card drawCard();     // Draws one card
    bool isEmpty() const;// Checks if deck is empty
};

#endif
