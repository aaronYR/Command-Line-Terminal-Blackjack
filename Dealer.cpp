#include "Dealer.h"
#include <iostream>
using namespace std;

// Makes a dealer
Dealer::Dealer() {}

// Dealer's turn logic
void Dealer::playTurn(Deck& deck) {
    cout << "\nDealer's turn...\n";
    showHand(false);

    // Dealer hits until reaching at least 17
    while (getHandValue() < 17) {
        cout << "Dealer hits...\n";
        addCard(deck.drawCard());
        showHand(false);
    }

    // Dealer outcome
    if (getHandValue() > 21)
        cout << "Dealer busts!\n";
    else
        cout << "Dealer stands.\n";
}
