#include "../headers/personajes/Caballero.h"

Caballero::Caballero() : Guerrero("Caballero", 100, 25, 20, 18) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    honorInquebrantable = distrib(gen);
    hp = honorInquebrantable ? hp + 10 : hp - 10;
}

int Caballero::getHP() const {
    return hp;
}