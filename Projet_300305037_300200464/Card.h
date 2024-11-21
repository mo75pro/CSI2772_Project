#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <fstream>
class Card {
public:
    // Obtenir le nombre de cartes pour un nombre donné de pièces
    virtual int getCardsPerCoin(int coins) const = 0;
    
    // Obtenir le nom de la carte
    virtual std::string getName() = 0;
    
    // Imprimer les détails de la carte
    virtual void print(std::ostream& out) const = 0;

    // Surcharge de l'opérateur << pour imprimer les détails de la carte
    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out);
        return out;
    }

    // Destructeur de la classe Card
    virtual ~Card() = default;

    // Sauvegarder les détails de la carte dans un fichier
    //void saveCard(std::ofstream& filename);
};

class Blue : public virtual Card {
    std::string name;
public:
    Blue(std::string name = "Blue");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};
class Chili : public virtual Card {
    std::string name;
public:
    Chili(std::string name = "Chili");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};
class Stink : public virtual Card {
    std::string name;
public:
    Stink(std::string name = "Stink");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};
class Green : public virtual Card {
    std::string name;
public:
    Green(std::string name = "Green");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};
class soy : public virtual Card {
    std::string name;
public:
    soy(std::string name = "soy");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};
class black : public virtual Card {
    std::string name;
public:
    black(std::string name = "black");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};

class Red : public virtual Card {
    std::string name;
public:
    Red(std::string = "Red");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};


class garden : public virtual Card {
    std::string name;
public:
    garden(std::string = "garden");
    int getCardsPerCoin(int coins);
    std::string getName();
    void print(std::ostream& out);
};

#endif // CARD_H
