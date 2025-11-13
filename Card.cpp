#include "Card.h"

// Makes a card with a rank and suit
Card::Card(string rank, string suit) {
    this->rank = rank;
    this->suit = suit;

    // Set card value
    if (rank == "J" || rank == "Q" || rank == "K")
        value = 10;
    else if (rank == "A")
        value = 11;
    else
        value = stoi(rank);
}

// Get the card rank
string Card::getRank() const {
    return rank;
}

// Get the card suit
string Card::getSuit() const {
    return suit;
}

// Get the card value
int Card::getValue() const {
    return value;
}

// Show the card on screen
void Card::showCard() const {
    cout << rank << " of " << suit << " (value: " << value << ")" << endl;
}
