#include "CardFactory.h"
#include "Card.h"

CardFactory* CardFactory::instance = nullptr;

CardFactory::CardFactory() {
    // Initialize card instances based on game requirements
}

CardFactory* CardFactory::getFactory() {
    if (!instance) {
        instance = new CardFactory();
    }
    return instance;
}

Deck CardFactory::getDeck() {
    Deck deck;
    // Create and add all required cards to the deck in correct quantities
    // Shuffle the deck to ensure randomness
    std::shuffle(deck.begin(), deck.end(), std::mt19937{std::random_device{}()});
    return deck;
}
