#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;

public:
    Table(const std::string& player1Name, const std::string& player2Name);
    Table(std::istream& in, const CardFactory* factory);

    bool win(std::string& winnerName) const;
    void printHand(bool showAll = false) const;

    Player& getPlayer1();
    Player& getPlayer2();
    Deck& getDeck();
    DiscardPile& getDiscardPile();
    TradeArea& getTradeArea();

    friend std::ostream& operator<<(std::ostream& out, const Table& table);
};

#endif // TABLE_H
