#include "../headers/personajes/Hechicero.h"

Hechicero::Hechicero() : Mago("Hechicero", 100, 100, 85, 70) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    auraMistica = distrib(gen);
    hp = auraMistica ? hp + 10 : hp - 10;
}

int Hechicero::getHP() const {
    return hp;
}