#include <deque>

class Hand {
private:
    deque<Card*> cards;

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

    Card* operator[](int index) {
        if (index < 0 || index >= cards.size()) {
            throw out_of_range("Index out of range");
        }
        return cards[index];
    }

    friend ostream& operator<<(ostream& out, const Hand& hand) {
        for (const auto& card : hand.cards) {
            out << *card << " ";
        }
        return out;
    }
};
