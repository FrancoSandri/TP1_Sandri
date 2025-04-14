#include "../headers/armas/Espada.h"
#include <random>

Espada::Espada() : ArmaCombate("Espada", "Corte", "Acero", 12, 60, 3.5f) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    estaAfilada = distrib(gen);
}
