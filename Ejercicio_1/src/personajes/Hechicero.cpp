#include "../headers/personajes/Hechicero.h"

Hechicero::Hechicero() : Mago("Hechicero", 100, 100, 85, 70) {
    int tipo = rand() % 2;
    auraMistica = tipo;
    hp = auraMistica ? hp + 10 : hp - 10;
}

int Hechicero::getHP() const {
    return hp;
}