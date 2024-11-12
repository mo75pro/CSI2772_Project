#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class NotEnoughCoins : public runtime_error {
public:
    NotEnoughCoins() : runtime_error("Not enough coins to buy a third chain") {}
};

class Player {
private:
    string name;
    int coins;
    int maxChains;
    vector<Chain<Card*>> chains;
    Hand* hand;

public:
    Player(const string& playerName) : name(playerName), coins(0), maxChains(2) {
        hand = new Hand();
    }

    ~Player() {
        delete hand;
    }

    string getName() const { return name; }

    int getNumCoins() const { return coins; }

    Player& operator+=(int additionalCoins) {
        coins += additionalCoins;
        return *this;
    }

    int getMaxNumChains() const { return maxChains; }

    int getNumChains() const { return chains.size(); }

    Chain<Card*>& operator[](int i) {
        if (i < 0 || i >= chains.size()) {
            throw out_of_range("Chain index out of range");
        }
        return chains[i];
    }

    void buyThirdChain() {
        if (coins >= 3 && maxChains == 2) {
            coins -= 3;
            maxChains = 3;
        } else {
            throw NotEnoughCoins();
        }
    }

    void printHand(ostream& out, bool showAll = false) const {
        if (showAll) {
            out << *hand;
        } else {
            out << *hand->top(); // Only display the top card if showAll is false
        }
    }

    friend ostream& operator<<(ostream& out, const Player& player) {
        out << player.name << "    " << player.coins << " coins\n";
        for (const auto& chain : player.chains) {
            out << chain << "\n";
        }
        return out;
    }
};
