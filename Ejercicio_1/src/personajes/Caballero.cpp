#include "../headers/personajes/Caballero.h"

Caballero::Caballero() : Guerrero("Caballero", 100, 25, 20, 18) {
    int tipo = rand() % 2;
    honorInquebrantable = tipo;
    hp = honorInquebrantable ? hp + 10 : hp - 10;
}

int Caballero::getHP() const {
    return hp;
}