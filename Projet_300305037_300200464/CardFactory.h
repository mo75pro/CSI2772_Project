#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Deck.h"

class CardFactory {
private:
    static CardFactory* instance;
    CardFactory();

public:
    static CardFactory* getFactory();
    Deck getDeck();
};

#endif // CARDFACTORY_H
