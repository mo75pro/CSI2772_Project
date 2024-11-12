#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <iostream>
#include <fstream>

#include <iostream>
#include <string>
using namespace std;

class Card {
public:
    virtual int getCardsPerCoin(int coins) const = 0; // Pure virtual function
    virtual string getName() const = 0;
    virtual void print(ostream& out) const = 0;

    // Virtual friend function for streaming
    friend ostream& operator<<(ostream& out, const Card& card) {
        card.print(out);
        return out;
    }

    virtual ~Card() = default; // Virtual destructor
};


#endif // CARD_H_INCLUDED
