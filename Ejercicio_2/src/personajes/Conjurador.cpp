#include "../headers/personajes/Conjurador.h"

Conjurador::Conjurador() : Mago("Conjurador", 100, 90, 75, 80) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    enlaceEter = distrib(gen);
}

int Conjurador::getHP() const {
    int hpBase = Mago::getHP();
    return enlaceEter ? hpBase + 10 : hpBase - 10;
}