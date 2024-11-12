#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include "Card.h"

class TradeArea {
private:
    std::list<Card*> tradeArea;

public:
    TradeArea& operator+=(Card* card);
    bool legal(Card* card) const;
    Card* trade(const std::string& cardName);
    int numCards() const;
    void print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea);
};

#endif // TRADEAREA_H
