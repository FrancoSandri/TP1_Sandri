#include "../headers/personajes/Mercenario.h"

Mercenario::Mercenario() : Guerrero("Mercenario", 100, 35, 10, 25) {
    int tipo = rand() % 2;
    instintoSupervivencia = tipo;
    hp = instintoSupervivencia ? hp + 10 : hp - 10;
}

int Mercenario::getHP() const {
    return hp;
}