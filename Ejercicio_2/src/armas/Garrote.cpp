#include "../headers/armas/Garrote.h"
#include <random>

Garrote::Garrote() : ArmaCombate("Garrote", "Contundente", "Roble", 15, 70, 4.5f) {
    // Generar ataquePesado aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    ataquePesado = distrib(gen);
}

int Garrote::getDanio() const {
    int danioBase = ArmaCombate::getDanio();
    if (ataquePesado) {
        return danioBase + 2; // Si tiene ataque pesado, suma 2
    } else {
        return danioBase - 1; // Si no tiene ataque pesado, resta 1
    }
}