#include "../headers/personajes/Nigromante.h"

Nigromante::Nigromante() : Mago("Nigromante", 100, 110, 95, 65) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esenciaNecrotica = distrib(gen);
}

int Nigromante::getHP() const {
    int hpBase = Mago::getHP();
    return esenciaNecrotica ? hpBase + 10 : hpBase - 10;
}