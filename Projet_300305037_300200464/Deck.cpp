#include <vector>
#include <algorithm>
#include <random>

class Deck : public vector<Card*> {
public:
    Card* draw() {
        if (empty()) return nullptr;
        Card* card = back();
        pop_back();
        return card;
    }

    void shuffleDeck() {
        std::shuffle(begin(), end(), std::mt19937{std::random_device{}()});
    }

    friend ostream& operator<<(ostream& out, const Deck& deck) {
        for (const auto& card : deck) {
            out << *card << " ";
        }
        return out;
    }
};
