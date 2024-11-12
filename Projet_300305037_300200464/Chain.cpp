#include <vector>

template <typename T>
class Chain {
private:
    vector<T*> chain;

public:
    Chain& operator+=(Card* card) {
        T* specificCard = dynamic_cast<T*>(card);
        if (specificCard) {
            chain.push_back(specificCard);
        } else {
            throw runtime_error("IllegalType");
        }
        return *this;
    }

    int sell() {
        if (chain.empty()) return 0;
        return chain.size() / chain[0]->getCardsPerCoin(1); // Example for 1 coin
    }

    friend ostream& operator<<(ostream& out, const Chain& c) {
        out << c.chain[0]->getName() << " ";
        for (const auto& card : c.chain) {
            out << *card << " ";
        }
        return out;
    }
};
