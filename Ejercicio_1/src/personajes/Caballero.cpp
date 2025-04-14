#include "../headers/personajes/Caballero.h"

Caballero::Caballero() : Guerrero("Caballero", 100, 25, 20, 18) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    honorInquebrantable = distrib(gen);
}

int Caballero::getHP() const {
    int hpBase = Guerrero::getHP();
    return honorInquebrantable ? hpBase + 10 : hpBase - 10;
}