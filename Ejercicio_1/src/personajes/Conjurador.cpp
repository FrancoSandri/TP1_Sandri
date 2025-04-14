#include "../headers/personajes/Conjurador.h"

Conjurador::Conjurador() : Mago("Conjurador", 100, 90, 75, 80) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    enlaceEter = distrib(gen);
    hp = enlaceEter ? hp + 10 : hp - 10;
}

int Conjurador::getHP() const {
    return hp;
}