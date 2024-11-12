#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
public:
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual std::string getName() const = 0;
    virtual void print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out);
        return out;
    }

    virtual ~Card() = default;
};

#endif // CARD_H
