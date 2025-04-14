#include "../headers/personajes/Nigromante.h"

Nigromante::Nigromante() : Mago("Nigromante", 100, 110, 95, 65) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esenciaNecrotica = distrib(gen);
    hp = esenciaNecrotica ? hp + 10 : hp - 10;
}

int Nigromante::getHP() const {
    return hp;
}