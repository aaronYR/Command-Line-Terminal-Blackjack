#ifndef DEALER_H
#define DEALER_H

#include "Participant.h"
#include "Deck.h"

// Dealer class for the game
class Dealer : public Participant {
public:
    Dealer();                 // Makes a dealer
    void playTurn(Deck& deck); // Dealer's move
};

#endif
