#include "../headers/personajes/Brujo.h"

Brujo::Brujo() : Mago("Brujo", 100, 85, 90, 60) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    pactoDemoniaco = distrib(gen);

    hp = pactoDemoniaco ? hp + 10 : hp - 10;
}

int Brujo::getHP() const {
    return hp;
}