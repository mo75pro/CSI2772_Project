#ifndef HAND_H
#define HAND_H

#include <deque>
#include <iostream>
#include "Card.h"

class Hand {
private:
    std::deque<Card*> cards; // Utilisation de deque pour un acc�s FIFO

public:
    // Ajoute une carte � la main du joueur (� la fin)
    Hand& operator+=(Card* card) {
        cards.push_back(card);
        return *this;
    }

    // Joue la premi�re carte de la main du joueur et la supprime de la main
    Card* play() {
        if (cards.empty()) return nullptr;
        Card* card = cards.front();
        cards.pop_front();
        return card;
    }

    // Renvoie la premi�re carte de la main sans la supprimer
    Card* top() const {
        if (cards.empty()) return nullptr;
        return cards.front();
    }

    // Renvoie une carte � une position donn�e sans la supprimer
    Card* operator[](int index) const {
        if (index < 0 || index >= cards.size()) {
            throw std::out_of_range("Index out of range");
        }
        return cards[index];
    }

    // Affiche toutes les cartes de la main dans l'ordre
    friend std::ostream& operator<<(std::ostream& out, const Hand& hand) {
        for (const auto& card : hand.cards) {
            out << *card << " ";
        }
        return out;
    }
};

#endif // HAND_H

