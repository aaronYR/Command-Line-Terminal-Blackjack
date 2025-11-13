#ifndef CARD_H     
#define CARD_H     

#include <string>
#include <iostream>
using namespace std;

// Card class for Blackjack
class Card {
private:
    string rank;   // Card name
    string suit;   // Card type
    int value;     // Card value

public:
    Card(string rank, string suit); // Makes a card
    string getRank() const;         // Gets rank
    string getSuit() const;         // Gets suit
    int getValue() const;           // Gets value
    void showCard() const;          // Shows card
};

#endif  
