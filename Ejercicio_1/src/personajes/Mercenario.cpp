#include "../headers/personajes/Mercenario.h"

Mercenario::Mercenario() : Guerrero("Mercenario", 100, 35, 10, 25) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    instintoSupervivencia = distrib(gen);
}

int Mercenario::getHP() const {
    int hpBase = Guerrero::getHP();
    return instintoSupervivencia ? hpBase + 10 : hpBase - 10;
}