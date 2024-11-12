#include <vector>

class DiscardPile {
private:
    vector<Card*> pile;

public:
    DiscardPile& operator+=(Card* card) {
        pile.push_back(card);
        return *this;
    }

    Card* pickUp() {
        if (pile.empty()) return nullptr;
        Card* card = pile.back();
        pile.pop_back();
        return card;
    }

    Card* top() const {
        if (pile.empty()) return nullptr;
        return pile.back();
    }

    void print(ostream& out) const {
        for (const auto& card : pile) {
            out << *card << " ";
        }
    }

    friend ostream& operator<<(ostream& out, const DiscardPile& discardPile) {
        discardPile.print(out);
        return out;
    }
};
