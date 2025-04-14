#include "../headers/armas/Lanza.h"
#include <random>

Lanza::Lanza() : ArmaCombate("Lanza", "Perforante", "Madera", 17, 55, 4.0f) {
    // Generar largoAlcance aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    largoAlcance = distrib(gen);
}