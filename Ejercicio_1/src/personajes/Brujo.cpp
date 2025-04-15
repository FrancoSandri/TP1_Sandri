#include "../headers/personajes/Brujo.h"

Brujo::Brujo() : Mago("Brujo", 100, 85, 90, 60) {
    int tipo = rand() % 2;
    pactoDemoniaco = tipo;
    hp = pactoDemoniaco ? hp + 10 : hp - 10;
}

int Brujo::getHP() const {
    return hp;
}