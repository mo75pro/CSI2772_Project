#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Card.h"

class IllegalType : public std::runtime_error {
public:
    IllegalType() : std::runtime_error("Attempted to add a card of the wrong type to the chain") {}
};

template <typename T>
class Chain {
private:
    std::vector<T*> chain;

public:
    Chain() = default;
    Chain(std::istream& in, const CardFactory* factory);

    Chain<T>& operator+=(Card* card) {
        T* specificCard = dynamic_cast<T*>(card);
        if (specificCard) {
            chain.push_back(specificCard);
        } else {
            throw IllegalType();
        }
        return *this;
    }

    int sell() const {
        if (chain.empty()) return 0;
        int numCards = chain.size();
        int coinsPerCard = chain[0]->getCardsPerCoin(1);
        return numCards / coinsPerCard;
    }

    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& c) {
        if (!c.chain.empty()) {
            out << c.chain[0]->getName() << " ";
            for (const auto& card : c.chain) {
                out << *card << " ";
            }
        }
        return out;
    }
};

#endif // CHAIN_H
