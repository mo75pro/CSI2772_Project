#include <iostream>

class Table {
private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;

public:
    Table(const string& player1Name, const string& player2Name)
        : player1(player1Name), player2(player2Name) {}

    bool win(string& winnerName) const {
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

    void printHand(bool showAll = false) const {
        cout << player1.getName() << "'s Hand: ";
        player1.printHand(cout, showAll);
        cout << endl;

        cout << player2.getName() << "'s Hand: ";
        player2.printHand(cout, showAll);
        cout << endl;
    }

    friend ostream& operator<<(ostream& out, const Table& table) {
        out << "Player 1: " << table.player1 << endl;
        out << "Player 2: " << table.player2 << endl;
        out << "Discard Pile: " << table.discardPile << endl;
        out << "Trade Area: " << table.tradeArea << endl;
        return out;
    }
};
