#include "../headers/personajes/Barbaro.h"

Barbaro::Barbaro() : Guerrero("Bárbaro", 100, 40, 5, 20) {
    int tipo = rand() % 2;
    furiaSalvaje = tipo;
    hp = furiaSalvaje ? hp + 10 : hp - 10;
}

int Barbaro::getHP() const {
    return hp;
}