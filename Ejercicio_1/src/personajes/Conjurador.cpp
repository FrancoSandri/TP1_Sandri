#include "../headers/personajes/Conjurador.h"

Conjurador::Conjurador() : Mago("Conjurador", 100, 90, 75, 80) {
    int tipo = rand() % 2;
    enlaceEter = tipo;
    hp = enlaceEter ? hp + 10 : hp - 10;
}

int Conjurador::getHP() const {
    return hp;
}