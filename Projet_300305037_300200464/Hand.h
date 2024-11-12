/*
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
*/
#ifndef HAND_H
#define HAND_H

#include <deque>
#include <iostream>
#include "Card.h"

class Hand {
private:
    std::deque<Card*> cards;

public:
    Hand& operator+=(Card* card) {
        cards.push_back(card);
        return *this;
    }

    Card* play() {
        if (cards.empty()) return nullptr;
        Card* card = cards.front();
        cards.pop_front();
        return card;
    }

    Card* top() const {
        if (cards.empty()) return nullptr;
        return cards.front();
    }

    Card* operator[](int index) const {
        if (index < 0 || index >= cards.size()) {
            throw std::out_of_range("Index out of range");
        }
        return cards[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Hand& hand) {
        for (const auto& card : hand.cards) {
            out << *card << " ";
        }
        return out;
    }
};

#endif // HAND_H
