#include <iostream>
#include <fstream>
#include "Table.h"
#include "CardFactory.h"

int main() {
    // Setup
    std::string player1Name, player2Name;
    Table* table;

    std::cout << "Do you want to load a saved game? (y/n): ";
    char loadGame;
    std::cin >> loadGame;

    if (loadGame == 'y') {
        std::ifstream file("saved_game.txt");
        if (file) {
            table = new Table(file, CardFactory::getFactory());
            file.close();
        }
        else {
            std::cerr << "Error loading game from file.\n";
            return 1;
        }
    }
    else {
        std::cout << "Enter name for Player 1: ";
        std::cin >> player1Name;
        std::cout << "Enter name for Player 2: ";
        std::cin >> player2Name;

        table = new Table(player1Name, player2Name);

        Deck deck = CardFactory::getFactory()->getDeck();
        for (int i = 0; i < 5; ++i) {
            table->getPlayer1().getHand() += deck.draw();
            table->getPlayer2().getHand() += deck.draw();
        }
        table->getDeck() = deck;
    }

    // Main game loop
    while (!table->getDeck().empty()) {
        std::cout << "Do you want to pause and save the game? (y/n): ";
        char pause;
        std::cin >> pause;
        if (pause == 'y') {
            std::ofstream file("saved_game.txt");
            file << *table;
            file.close();
            std::cout << "Game saved! Exiting...\n";
            break;
        }

        // For each player
        for (int playerIndex = 0; playerIndex < 2; ++playerIndex) {
            Player& currentPlayer = (playerIndex == 0) ? table->getPlayer1() : table->getPlayer2();
            std::cout << "Current player: " << currentPlayer.getName() << std::endl;

            // Display the current table state
            std::cout << *table << std::endl;

            // Player draws the top card from the deck
            currentPlayer.getHand() += table->getDeck().draw();

            // Check and process cards in the TradeArea
            if (!table->getTradeArea().empty()) {
                for (Card* card : table->getTradeArea()) {
                    // The player decides whether to add to a chain or discard each card
                    std::cout << "Do you want to chain the card " << *card << "? (y/n): ";
                    char choice;
                    std::cin >> choice;
                    if (choice == 'y') {
                        // Logic to add the card to a chain goes here
                    }
                    else {
                        table->getDiscardPile() += card;
                    }
                }
                table->getTradeArea().clear();
            }

            // Player plays the topmost card from their hand
            Card* topCard = currentPlayer.getHand().play();
            if (topCard) {
                // Process the card in the chain; if chain is completed, add coins to the player
            }

            // Player may choose to play another card from hand
            std::cout << "Do you want to play the next card from your hand? (y/n): ";
            char playAgain;
            std::cin >> playAgain;
            if (playAgain == 'y') {
                Card* nextTopCard = currentPlayer.getHand().play();
                if (nextTopCard) {
                    // Process the card in the chain; if chain is completed, add coins to the player
                }
            }

            // Player may choose to discard an arbitrary card from their hand
            std::cout << "Do you want to discard an arbitrary card from your hand? (y/n): ";
            char discardChoice;
            std::cin >> discardChoice;
            if (discardChoice == 'y') {
                // Display the player's hand and allow them to choose a card to discard
                table->getDiscardPile() += currentPlayer.getHand().play(); // Placeholder for chosen card
            }

            // Draw three cards from the deck and place them in the trade area
            for (int i = 0; i < 3; ++i) {
                table->getTradeArea() += table->getDeck().draw();
            }

            // Move matching cards from discard pile to trade area
            while (table->getDiscardPile().top() && table->getTradeArea().legal(table->getDiscardPile().top())) {
                table->getTradeArea() += table->getDiscardPile().pickUp();
            }

            // Process cards in the trade area for chaining or leaving for the next player
            for (Card* card : table->getTradeArea()) {
                std::cout << "Do you want to chain the card " << *card << "? (y/n): ";
                char chainChoice;
                std::cin >> chainChoice;
                if (chainChoice == 'y') {
                    // Logic to add the card to a chain goes here
                }
            }

            // Draw two additional cards to the player's hand
            currentPlayer.getHand() += table->getDeck().draw();
            currentPlayer.getHand() += table->getDeck().draw();
        }
    }

    // Check for winner
    std::string winnerName;
    if (table->win(winnerName)) {
        std::cout << "The winner is " << winnerName << "!" << std::endl;
    }
    else {
        std::cout << "No winner yet." << std::endl;
    }

    delete table;
    return 0;
}
