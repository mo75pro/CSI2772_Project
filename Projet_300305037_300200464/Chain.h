#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Card.h"

// Classe d'exception pour les cartes d'un type illégal
class IllegalType : public std::runtime_error {
public:
    IllegalType() : std::runtime_error("Attempted to add a card of the wrong type to the chain") {}
};

// Classe template Chain pour gérer une chaîne de cartes d'un type spécifique
template <typename T>
class Chain {
private:
    std::vector<T*> chain; // Stocke les cartes de type T dans la chaîne

public:
    // Constructeur par défaut
    Chain() = default;

    // Constructeur qui initialise la chaîne à partir d'un istream
    Chain(std::istream& in, const CardFactory* factory) {
        // Charger les cartes à partir du flux d'entrée (en supposant un format approprié)
        T* card;
        while (in >> card) {
            chain.push_back(card);
        }
    }

    // Ajoute une carte à la chaîne
    Chain<T>& operator+=(Card* card) {
        T* specificCard = dynamic_cast<T*>(card);
        if (specificCard) {
            chain.push_back(specificCard);
        } else {
            throw IllegalType();
        }
        return *this;
    }

    // Vend la chaîne et retourne le nombre de pièces gagnées
    int sell() const {
        if (chain.empty()) return 0;
        int numCards = chain.size();
        int coins = chain[0]->getCardsPerCoin(1); // Utiliser les cartes par pièce du premier élément
        return numCards / coins;
    }

    // Affiche la chaîne dans un flux
    friend std::ostream& operator<<(std::ostream& out, const Chain<T>& c) {
        if (!c.chain.empty()) {
            out << c.chain[0]->getName() << "\t";
            for (const auto& card : c.chain) {
                out << *card << " ";
            }
        }
        return out;
    }
};

#endif // CHAIN_H

