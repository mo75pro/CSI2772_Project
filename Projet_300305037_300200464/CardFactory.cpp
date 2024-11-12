#include <memory>

class CardFactory {
private:
    static CardFactory* instance;

    CardFactory() = default;

public:
    static CardFactory* getFactory() {
        if (!instance) {
            instance = new CardFactory();
        }
        return instance;
    }

    Deck getDeck() {
        Deck deck;
        // Create all 104 cards and add to the deck (e.g., 20 Blue, 18 Chili)
        // Note: Add code here to create each card type with the correct count.
        deck.shuffleDeck();
        return deck;
    }

    CardFactory(const CardFactory&) = delete;
    CardFactory& operator=(const CardFactory&) = delete;
};

CardFactory* CardFactory::instance = nullptr;
