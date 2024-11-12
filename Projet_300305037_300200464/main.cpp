#include <iostream>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Table.h"

using namespace std;

void saveGame(const Table& table) {
    // Implement the function to save the current game state to a file
    cout << "Game saved!" << endl;
}

void loadGame(Table& table) {
    // Implement the function to load a saved game from a file
    cout << "Game loaded!" << endl;
}

int main() {
    // Initial Setup
    string player1Name, player2Name;
    cout << "Enter name for Player 1: ";
    cin >> player1Name;
    cout << "Enter name for Player 2: ";
    cin >> player2Name;

    // Create game components
    Table table(player1Name, player2Name);
    Deck deck = CardFactory::getFactory()->getDeck(); // Initialize deck
    DiscardPile discardPile;
    TradeArea tradeArea;

    // Draw initial cards for each player
    for (int i = 0; i < 5; ++i) {
        table.getPlayer1().getHand() += deck.draw();
        table.getPlayer2().getHand() += deck.draw();
    }

    bool gamePaused = false;

    // Main game loop
    while (!deck.empty()) {
        // Check if game should be paused and saved
        if (gamePaused) {
            saveGame(table);
            break;
        }

        // Each player's turn
        for (int playerIndex = 0; playerIndex < 2; ++playerIndex) {
            Player& currentPlayer = (playerIndex == 0) ? table.getPlayer1() : table.getPlayer2();
            cout << "Current player: " << currentPlayer.getName() << endl;

            // Display the current table state
            cout << table << endl;

            // Player draws the top card from the deck
            currentPlayer.getHand() += deck.draw();

            // Check and process cards in the TradeArea
            if (!tradeArea.empty()) {
                // Add cards from TradeArea to chains or discard them
                // (Logic for adding or discarding based on player decisions)
            }

            // Player plays the topmost card from hand
            Card* topCard = currentPlayer.getHand().play();
            if (topCard) {
                // Process the card in the chain
                // If chain is completed, remove cards from chain and add coins to player
            }

            // Check if player wants to play another card from hand
            bool playAnother = false;
            cout << "Do you want to play another card? (y/n): ";
            char choice;
            cin >> choice;
            playAnother = (choice == 'y');

            if (playAnother) {
                Card* nextTopCard = currentPlayer.getHand().play();
                if (nextTopCard) {
                    // Process this card as well
                }
            }

            // Check if player wants to discard an arbitrary card from hand
            cout << "Do you want to discard an arbitrary card from your hand? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                // Show the player's hand and let them choose a card to discard
                // Move chosen card to discardPile
            }

            // Draw three cards from the deck and place them in the trade area
            for (int i = 0; i < 3; ++i) {
                tradeArea += deck.draw();
            }

            // Check if the top of discard pile matches cards in trade area
            while (discardPile.top() && tradeArea.contains(discardPile.top()->getName())) {
                tradeArea += discardPile.pickUp();
            }

            // Process cards in trade area for chaining or leaving for the next player
            // (Player chooses whether to chain or leave each card)

            // Draw two cards from deck and add to the back of player's hand
            currentPlayer.getHand() += deck.draw();
            currentPlayer.getHand() += deck.draw();
        }
    }

    // Determine winner
    string winnerName;
    if (table.win(winnerName)) {
        cout << "The winner is " << winnerName << "!" << endl;
    } else {
        cout << "No winner yet." << endl;
    }

    return 0;
}
