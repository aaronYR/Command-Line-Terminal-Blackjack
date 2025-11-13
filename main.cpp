#include <iostream>
#include <fstream>   
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
using namespace std;

int main() {
    char playAgain;

    do {
        try {
            // Create and shuffle the deck
            Deck deck;
            deck.shuffleDeck();

            // Create dealer and player
            Dealer dealer;
            Player player;

            // Deal initial cards
            player.addCard(deck.drawCard());
            dealer.addCard(deck.drawCard());
            player.addCard(deck.drawCard());
            dealer.addCard(deck.drawCard());

            // Show both hands
            cout << "\nDealer's hand:\n";
            dealer.showHand(true);

            cout << "\nPlayer's hand:\n";
            player.showHand(false);

            // Player turn
            player.takeTurn(deck);

            // Dealer turn (if player didn’t bust)
            if (player.getHandValue() <= 21) {
                dealer.playTurn(deck);
            }

            // Show final results
            cout << "\n--- Final Results ---\n";
            cout << "Dealer's total: " << dealer.getHandValue() << endl;
            cout << "Player's total: " << player.getHandValue() << endl;

            // Decide winner
            if (player.getHandValue() > 21) {
                cout << "\nYou busted! Dealer wins.\n";
            } else if (dealer.getHandValue() > 21) {
                cout << "\nDealer busted! You win!\n";
            } else if (dealer.getHandValue() > player.getHandValue()) {
                cout << "\nDealer wins!\n";
            } else if (dealer.getHandValue() < player.getHandValue()) {
                cout << "\nYou win!\n";
            } else {
                cout << "\nIt's a tie!\n";
            }

            // Log the round result
            ofstream log("game_log.txt");
            time_t now = time(NULL);
            log << "Round completed at " << ctime(&now);
            log << "Dealer: " << dealer.getHandValue()
                << " | Player: " << player.getHandValue() << "\n\n";
            log.close();
        }
        catch (...) {
            // Handle any error
            cout << "An error occurred. Restarting with a new deck..." << endl;
            Deck newDeck;
            newDeck.shuffleDeck();
        }

        // Ask player to play again
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

        // Validate input
        while (playAgain != 'y' && playAgain != 'Y' &&
               playAgain != 'n' && playAgain != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> playAgain;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    // End message
    cout << "\nThanks for playing Blackjack!\n";
    return 0;
}
