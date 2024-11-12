#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck : public std::vector<Card*> {
public:
    Card* draw();
    void shuffleDeck();

    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
};

#endif // DECK_H
