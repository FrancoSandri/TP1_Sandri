#include "../headers/armas/Garrote.h"
#include <random>

Garrote::Garrote() : ArmaCombate("Garrote", "Contundente", "Roble", 15, 70, 4.5f) {
    // Generar ataquePesado aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    ataquePesado = distrib(gen);
}