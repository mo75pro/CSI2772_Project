#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include "Card.h"

class DiscardPile {
private:
    std::vector<Card*> pile;

public:
    DiscardPile& operator+=(Card* card);
    Card* pickUp();
    Card* top() const;
    void print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& discardPile);
};

#endif // DISCARDPILE_H
