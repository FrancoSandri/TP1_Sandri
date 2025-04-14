#include "../headers/personajes/Gladiador.h"

Gladiador::Gladiador() : Guerrero("Gladiador", 100, 28, 12, 22) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    gloriaCombate = distrib(gen);
}

int Gladiador::getHP() const {
    int hpBase = Guerrero::getHP();
    return gloriaCombate ? hpBase + 10 : hpBase - 10;
}