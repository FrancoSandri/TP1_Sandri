#include "../headers/personajes/Barbaro.h"

Barbaro::Barbaro() : Guerrero("Bárbaro", 100, 40, 5, 20) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    furiaSalvaje = distrib(gen);
    hp = furiaSalvaje ? hp + 10 : hp - 10;
}

int Barbaro::getHP() const {
    return hp;
}