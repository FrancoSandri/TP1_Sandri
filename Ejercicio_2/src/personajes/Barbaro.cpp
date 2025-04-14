#include "../headers/personajes/Barbaro.h"

Barbaro::Barbaro() : Guerrero("Bárbaro", 100, 40, 5, 20) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    furiaSalvaje = distrib(gen);
}

int Barbaro::getHP() const {
    int hpBase = Guerrero::getHP();
    return furiaSalvaje ? hpBase + 10 : hpBase - 10;
}