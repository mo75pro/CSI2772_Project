#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Card.h"

// Classe d'exception pour les cartes d'un type ill�gal
class IllegalType : public std::runtime_error {
public:
    IllegalType() : std::runtime_error("Attempted to add a card of the wrong type to the chain") {}
};

// Classe template Chain pour g�rer une cha�ne de cartes d'un type sp�cifique
template <typename T>
class Chain {
private:
    std::vector<T*> chain; // Stocke les cartes de type T dans la cha�ne

public:
    // Constructeur par d�faut
    Chain() = default;

    // Constructeur qui initialise la cha�ne � partir d'un istream
    Chain(std::istream& in, const CardFactory* factory) {
        // Charger les cartes � partir du flux d'entr�e (en supposant un format appropri�)
        T* card;
        while (in >> card) {
            chain.push_back(card);
        }
    }

    // Ajoute une carte � la cha�ne
    Chain<T>& operator+=(Card* card) {
        T* specificCard = dynamic_cast<T*>(card);
        if (specificCard) {
            chain.push_back(specificCard);
        } else {
            throw IllegalType();
        }
        return *this;
    }

    // Vend la cha�ne et retourne le nombre de pi�ces gagn�es
    int sell() const {
        if (chain.empty()) return 0;
        int numCards = chain.size();
        int coins = chain[0]->getCardsPerCoin(1); // Utiliser les cartes par pi�ce du premier �l�ment
        return numCards / coins;
    }

    // Affiche la cha�ne dans un flux
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

