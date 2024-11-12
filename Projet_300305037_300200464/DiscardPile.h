#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include "Card.h"

class DiscardPile {
private:
    std::vector<Card*> pile;

public:
    DiscardPile& operator+=(Card* card) {
        pile.push_back(card);
        return *this;
    }

    Card* pickUp() {
        if (pile.empty()) return nullptr;
        Card* topCard = pile.back();
        pile.pop_back();
        return topCard;
    }

    Card* top() const {
        if (pile.empty()) return nullptr;
        return pile.back();
    }

    void print(std::ostream& out) const {
        for (const auto& card : pile) {
            out << *card << " ";
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& discardPile) {
        discardPile.print(out);
        return out;
    }
};

#endif // DISCARDPILE_H
