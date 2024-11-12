#include "Player.h"
#include <stdexcept>

Player::Player(const std::string& playerName)
    : name(playerName), coins(0), maxChains(2) {}

Player::Player(std::istream& in, const CardFactory* factory) {
    // Logic to load player from file stream goes here
}

std::string Player::getName() const {
    return name;
}

int Player::getNumCoins() const {
    return coins;
}

Player& Player::operator+=(int additionalCoins) {
    coins += additionalCoins;
    return *this;
}

int Player::getMaxNumChains() const {
    return maxChains;
}

int Player::getNumChains() const {
    return chains.size();
}

Chain<Card*>& Player::operator[](int i) {
    if (i < 0 || i >= chains.size()) {
        throw std::out_of_range("Chain index out of range");
    }
    return chains[i];
}

void Player::buyThirdChain() {
    if (coins >= 3 && maxChains == 2) {
        coins -= 3;
        maxChains = 3;
    } else {
        throw NotEnoughCoins();
    }
}

void Player::printHand(std::ostream& out, bool showAll) const {
    if (showAll) {
        out << hand;
    } else {
        out << *hand.top();
    }
}

Hand& Player::getHand() {
    return hand;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << player.name << " " << player.coins << " coins\n";
    for (const auto& chain : player.chains) {
        out << chain << "\n";
    }
    return out;
}
