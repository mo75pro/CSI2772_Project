#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck : public std::vector<Card*> {
public:
    Card* draw() {
        if (this->empty()) return nullptr;
        Card* topCard = this->back();
        this->pop_back();
        return topCard;
    }

    friend std::ostream& operator<<(std::ostream& out, const Deck& deck) {
        for (const auto& card : deck) {
            out << *card << " ";
        }
        return out;
    }
};

#endif // DECK_H

