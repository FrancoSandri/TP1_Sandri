#include "../headers/armas/Espada.h"
#include <random>

Espada::Espada() : ArmaCombate("Espada", "Corte", "Acero", 12, 60, 3.5f) {
    int tipo = rand() % 2;
    estaAfilada = tipo;
    filo = estaAfilada ? filo + 5 : filo - 5; 
}
