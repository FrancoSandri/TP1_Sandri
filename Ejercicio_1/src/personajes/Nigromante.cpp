#include "../headers/personajes/Nigromante.h"

Nigromante::Nigromante() : Mago("Nigromante", 100, 110, 95, 65) {
    int tipo = rand() % 2;
    esenciaNecrotica = tipo;
    hp = esenciaNecrotica ? hp + 10 : hp - 10;
}

int Nigromante::getHP() const {
    return hp;
}