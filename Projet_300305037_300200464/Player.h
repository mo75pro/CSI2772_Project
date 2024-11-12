#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include "Hand.h"
#include "Chain.h"
#include "Card.h"

class NotEnoughCoins : public std::runtime_error {
public:
    NotEnoughCoins() : std::runtime_error("Not enough coins to buy a third chain") {}
};

class Player {
private:
    std::string name;
    int coins;
    int maxChains;
    std::vector<Chain<Card*>> chains;
    Hand hand;

public:
    Player(const std::string& playerName);
    Player(std::istream& in, const CardFactory* factory);

    std::string getName() const;
    int getNumCoins() const;
    Player& operator+=(int additionalCoins);
    int getMaxNumChains() const;
    int getNumChains() const;
    Chain<Card*>& operator[](int i);
    void buyThirdChain();
    void printHand(std::ostream& out, bool showAll = false) const;
    Hand& getHand();

    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

#endif // PLAYER_H
