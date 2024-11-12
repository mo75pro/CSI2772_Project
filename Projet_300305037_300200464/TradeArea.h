/*
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
*/
#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include <string>
#include "Card.h"

class TradeArea {
private:
    std::list<Card*> tradeArea;

public:
    TradeArea& operator+=(Card* card) {
        tradeArea.push_back(card);
        return *this;
    }

    bool legal(Card* card) const {
        for (const auto& c : tradeArea) {
            if (c->getName() == card->getName()) {
                return true;
            }
        }
        return false;
    }

    Card* trade(const std::string& cardName) {
        for (auto it = tradeArea.begin(); it != tradeArea.end(); ++it) {
            if ((*it)->getName() == cardName) {
                Card* card = *it;
                tradeArea.erase(it);
                return card;
            }
        }
        return nullptr;
    }

    int numCards() const {
        return tradeArea.size();
    }

    friend std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
        for (const auto& card : tradeArea.tradeArea) {
            out << *card << " ";
        }
        return out;
    }
};

#endif // TRADEAREA_H
