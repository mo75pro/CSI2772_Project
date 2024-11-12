#ifndef HAND_H
#define HAND_H

#include <deque>
#include <iostream>
#include "Card.h"

class Hand {
private:
    std::deque<Card*> cards;
s
public:
    Hand& operator+=(Card* card);
    Card* play();
    Card* top() const;
    Card* operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& out, const Hand& hand);
};

#endif // HAND_H
