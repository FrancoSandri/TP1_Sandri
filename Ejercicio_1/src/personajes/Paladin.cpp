#include "../headers/personajes/Paladin.h"

Paladin::Paladin() : Guerrero("Paladín", 100, 30, 15, 15) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    bendicionDivina = distrib(gen);
    hp = bendicionDivina ? hp + 10 : hp - 10;
}

int Paladin::getHP() const {
    return hp;
}