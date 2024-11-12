#include "TradeArea.h"
#include <algorithm>

// Adds a card to the trade area without checking legality
TradeArea& TradeArea::operator+=(Card* card) {
    tradeArea.push_back(card);
    return *this;
}

// Checks if a card can be legally added to the trade area
// Returns true if a card of the same bean type already exists in the trade area
bool TradeArea::legal(Card* card) const {
    for (const auto& existingCard : tradeArea) {
        if (existingCard->getName() == card->getName()) {
            return true;
        }
    }
    return false;
}

// Removes and returns a card with the specified name from the trade area
Card* TradeArea::trade(const std::string& cardName) {
    auto it = std::find_if(tradeArea.begin(), tradeArea.end(),
                           [&cardName](Card* card) { return card->getName() == cardName; });
    if (it != tradeArea.end()) {
        Card* card = *it;
        tradeArea.erase(it);
        return card;
    }
    return nullptr;
}

// Returns the number of cards currently in the trade area
int TradeArea::numCards() const {
    return tradeArea.size();
}

// Prints all cards in the trade area to the specified output stream
void TradeArea::print(std::ostream& out) const {
    for (const auto& card : tradeArea) {
        out << *card << " ";
    }
}

// Overload of the output operator for displaying the TradeArea
std::ostream& operator<<(std::ostream& out, const TradeArea& tradeArea) {
    tradeArea.print(out);
    return out;
}
