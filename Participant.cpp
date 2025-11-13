#include "Participant.h"

// Adds a card to the player's or dealer's hand
void Participant::addCard(Card card) {
    hand.push_back(card);
}

// Calculates the total value of the hand (used for game logic)
int Participant::getHandValue() const {
    int total = 0;
    int aces = 0;

    for (int i = 0; i < hand.size(); ++i) {
        total += hand[i].getValue();
        if (hand[i].getRank() == "A")
            aces++;
    }

    // Adjust Ace value if total > 21
    while (total > 21 && aces > 0) {
        total -= 10; // counts one Ace as 1 instead of 11
        aces--;
    }

    return total;
}

// Displays the cards in the hand
void Participant::showHand(bool hideFirstCard) const {
    int total = getHandValue();
    int aces = 0;

    for (size_t i = 0; i < hand.size(); ++i) {
        if (hideFirstCard && i == 0) {
            cout << "[Hidden Card]" << endl;
        } else {
            hand[i].showCard();
        }
    }
    // If hiding first card (e.g., dealer's initial hand), hide total too
    if (hideFirstCard)
        cout << "Total value: ???" << endl;
    else
        cout << "Total value: " << total << endl;
}
