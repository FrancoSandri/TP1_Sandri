#include "../headers/personajes/Hechicero.h"

Hechicero::Hechicero() : Mago("Hechicero", 100, 100, 85, 70) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    auraMistica = distrib(gen);
}

int Hechicero::getHP() const {
    int hpBase = Mago::getHP();
    return auraMistica ? hpBase + 10 : hpBase - 10;
}