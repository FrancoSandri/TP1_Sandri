#include "../headers/armas/Garrote.h"
#include <random>

Garrote::Garrote() : ArmaCombate("Garrote", "Contundente", "Roble", 15, 70, 4.5f) {
    int tipo = rand() % 2;
    ataquePesado = tipo;
    filo = ataquePesado ? filo + 5 : filo - 5; 
}