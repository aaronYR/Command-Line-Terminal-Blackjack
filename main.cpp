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
            srand(time(NULL)); 
            // Creates and shuffles the deck using the Fisher-Yates algorithm
            Deck deck;
            deck.shuffleDeck();

            // Create dealer and player
            Dealer dealer;
            Player player;

            // Cards are given to both dealer and player 
            player.addCard(deck.drawCard());
            dealer.addCard(deck.drawCard());
            player.addCard(deck.drawCard());
            dealer.addCard(deck.drawCard());

            cout << "\nDealer's hand:\n";
            dealer.showHand(true);

            cout << "\nPlayer's hand:\n";
            player.showHand(false);

            player.takeTurn(deck);

            // Dealer turn (if player didn’t bust)
            if (player.getHandValue() <= 21) {
                dealer.playTurn(deck);
            }

            // Shows the final results
            cout << "\n--- Final Results ---\n";
            cout << "Dealer's total: " << dealer.getHandValue() << endl;
            cout << "Player's total: " << player.getHandValue() << endl;

            // Decides winner based on bust or closest to 21
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

            // Logs the round result to game_log.txt
            ofstream fout("game_log.txt", ios::app);
            time_t now = time(NULL);
            fout << "Round completed at " << ctime(&now);
            fout << "Dealer: " << dealer.getHandValue()
                << " | Player: " << player.getHandValue() << endl;
            fout << "------------------------------\n";
            fout.close();
        }
        catch (...) {
            // Handles any error
            cout << "An error occurred. Restarting with a new deck..." << endl;
            Deck newDeck;
            newDeck.shuffleDeck();
        }

        // Ask player to play again
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

        // Validates input to only accept 'y' 'Y' 'n' 'N'
        while (playAgain != 'y' && playAgain != 'Y' &&
               playAgain != 'n' && playAgain != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> playAgain;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    // End of the game 
    cout << "\nThanks for playing Blackjack!\n";
    return 0;
}
