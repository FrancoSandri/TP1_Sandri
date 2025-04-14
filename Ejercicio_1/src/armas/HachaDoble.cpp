#include "../headers/armas/HachaDoble.h"
#include <random>

HachaDoble::HachaDoble() : ArmaCombate("Hacha Doble", "Corte", "Acero", 20, 40, 5.0f) {
    // Generar GiroRapido aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    GiroRapido = distrib(gen);
}
