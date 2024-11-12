#include "Table.h"

Table::Table(const std::string& player1Name, const std::string& player2Name)
    : player1(player1Name), player2(player2Name) {}

Table::Table(std::istream& in, const CardFactory* factory) {
    // Logic to load table from file stream goes here
}

bool Table::win(std::string& winnerName) const {
    if (deck.empty()) {
        if (player1.getNumCoins() > player2.getNumCoins()) {
            winnerName = player1.getName();
            return true;
        } else if (player2.getNumCoins() > player1.getNumCoins()) {
            winnerName = player2.getName();
            return true;
        }
    }
    return false;
}

void Table::printHand(bool showAll) const {
    std::cout << player1.getName() << "'s Hand: ";
    player1.printHand(std::cout, showAll);
    std::cout << "\n";

    std::cout << player2.getName() << "'s Hand: ";
    player2.printHand(std::cout, showAll);
    std::cout << "\n";
}

Player& Table::getPlayer1() { return player1; }
Player& Table::getPlayer2() { return player2; }
Deck& Table::getDeck() { return deck; }
DiscardPile& Table::getDiscardPile() { return discardPile; }
TradeArea& Table::getTradeArea() { return tradeArea; }

std::ostream& operator<<(std::ostream& out, const Table& table) {
    out << "Player 1: " << table.player1 << "\n";
    out << "Player 2: " << table.player2 << "\n";
    out << "Discard Pile: " << table.discardPile << "\n";
    out << "Trade Area: " << table.tradeArea << "\n";
    return out;
}
