#include "../headers/personajes/Paladin.h"

Paladin::Paladin() : Guerrero("Paladín", 100, 30, 15, 15) {
    int tipo = rand() % 2;
    bendicionDivina = tipo;
    hp = bendicionDivina ? hp + 10 : hp - 10;
}

int Paladin::getHP() const {
    return hp;
}