#include "../headers/personajes/Brujo.h"

Brujo::Brujo() : Mago("Brujo", 100, 85, 90, 60) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    pactoDemoniaco = distrib(gen);
}

int Brujo::getHP() const {
    int hpBase = Mago::getHP();
    return pactoDemoniaco ? hpBase + 10 : hpBase - 10;
}