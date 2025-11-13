#include "Player.h"
#include <iostream>
using namespace std;

// Makes a player
Player::Player() {}

// Player's turn logic
void Player::takeTurn(Deck& deck) {
    char choice;
    bool standing = false;

    // Keep playing until stand or bust
    while (!standing && getHandValue() < 21) {
        cout << "\nHit or stand? (h/s): ";
        cin >> choice;

        // Player chooses to hit
        if (choice == 'h' || choice == 'H') {
            addCard(deck.drawCard());
            cout << "\nYou drew:\n";
            hand.back().showCard();
            cout << "\nPlayer's hand:\n";
            showHand(false);
        }
        // Player chooses to stand
        else if (choice == 's' || choice == 'S') {
            standing = true;
        }
    }

    // Check if player busts
    if (getHandValue() > 21)
        cout << "\nYou busted!\n";
}
