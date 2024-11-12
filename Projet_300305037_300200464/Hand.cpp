#include "Hand.h"
#include <stdexcept>

Hand& Hand::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

Card* Hand::play() {
    if (cards.empty()) return nullptr;
    Card* card = cards.front();
    cards.pop_front();
    return card;
}

Card* Hand::top() const {
    if (cards.empty()) return nullptr;
    return cards.front();
}

Card* Hand::operator[](int index) const {
    if (index < 0 || index >= cards.size()) {
        throw std::out_of_range("Index out of range");
    }
    return cards[index];
}

std::ostream& operator<<(std::ostream& out, const Hand& hand) {
    for (const auto& card : hand.cards) {
        out << *card << " ";
    }
    return out;
}
