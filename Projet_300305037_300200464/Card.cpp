#include "Card.h"
#include <iostream>
using namespace std;

// Destructeur de la classe Card
Card::~Card() {}

// Implémentation du constructeur de la classe Blue
Blue::Blue(std::string name) {
    this->name = name; // Initialise le nom de la carte Blue
}


int Blue::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
        default: return 0;
    }
}

string Blue::getName() {
    return this->name;
}

void Blue::print(std::ostream& out) {
    out << this->getName()[0];
}

// Similarly, you would create classes for Chili, Stink, Green, Soy, Black, Red, and Garden with their respective values.

Chili::Chili(std::string name) {
    this->name = name; // Initialise le nom de la carte Chilie
}


int Chili::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 3;
    case 2: return 6;
    case 3: return 8;
    case 4: return 9;
    default: return 0;
    }
}

string Chili::getName() {
    return this->name;
}

void Chili::print(std::ostream& out) {
    out << this->getName()[0];
}

Stink::Stink(std::string name) {
    this->name = name; // Initialise le nom de la carte Stink
}


int Stink::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 3;
    case 2: return 5;
    case 3: return 7;
    case 4: return 8;
    default: return 0;
    }
}

string Stink::getName() {
    return this->name;
}

void Stink::print(std::ostream& out) {
    out << this->getName()[0];
}

Green::Green(std::string name) {
    this->name = name; // Initialise le nom de la carte Green
}


int Green::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 3;
    case 2: return 5;
    case 3: return 6;
    case 4: return 7;
    default: return 0;
    }
}

string Green::getName() {
    return this->name;
}

void Green::print(std::ostream& out) {
    out << this->getName()[0];
}

soy::soy(std::string name) {
    this->name = name; // Initialise le nom de la carte soy
}


int soy::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 2;
    case 2: return 4;
    case 3: return 6;
    case 4: return 7;
    default: return 0;
    }
}

string soy::getName() {
    return this->name;
}

void soy::print(std::ostream& out) {
    out << this->getName()[0];
}

black::black(std::string name) {
    this->name = name; // Initialise le nom de la carte black
}


int black::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 2;
    case 2: return 4;
    case 3: return 5;
    case 4: return 6;
    default: return 0;
    }
}

string black::getName() {
    return this->name;
}

void black::print(std::ostream& out) {
    out << this->getName()[0];
}

Red::Red(std::string name) {
    this->name = name; // Initialise le nom de la carte Red
}


int Red::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    case 4: return 5;
    default: return 0;
    }
}

string Red::getName() {
    return this->name;
}

void Red::print(std::ostream& out) {
    out << this->getName()[0];
}

garden::garden(std::string name) {
    this->name = name; // Initialise le nom de la carte garden
}


int garden::getCardsPerCoin(int coins) {
    switch (coins) {
        // Cas pour différentes valeurs de pièces avec un nombre correspondant de cartes
    case 1: return 0;
    case 2: return 2;
    case 3: return 3;
    case 4: return 0;
    default: return 0;
    }
}

string garden::getName() {
    return this->name;
}

void garden::print(std::ostream& out) {
    out << this->getName()[0];
}

