#include "../headers/personajes/Gladiador.h"

Gladiador::Gladiador() : Guerrero("Gladiador", 100, 28, 12, 22) {
    int tipo = rand() % 2;
    gloriaCombate = tipo;
    hp = gloriaCombate ? hp + 10 : hp - 10;
}

int Gladiador::getHP() const {
    return hp;
}