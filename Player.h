#ifndef PLAYER_H
#define PLAYER_H

#include "Participant.h"
#include "Deck.h"
#include <iostream>
using namespace std;

// Player class for user actions
class Player : public Participant {
public:
    Player();                // Makes a player
    void takeTurn(Deck& deck); // Player's move
};

#endif
