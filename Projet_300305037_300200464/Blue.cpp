class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch(coins) {
            case 1: return 4;
            case 2: return 6;
            case 3: return 8;
            case 4: return 10;
            default: return 0;
        }
    }

    string getName() const override { return "Blue"; }

    void print(ostream& out) const override {
        out << "B"; // Represents Blue card with 'B'
    }
};
