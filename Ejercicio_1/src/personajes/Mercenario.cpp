#include "../headers/personajes/Mercenario.h"

Mercenario::Mercenario() : Guerrero("Mercenario", 100, 35, 10, 25) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    instintoSupervivencia = distrib(gen);
    hp = instintoSupervivencia ? hp + 10 : hp - 10;
}

int Mercenario::getHP() const {
    return hp;
}