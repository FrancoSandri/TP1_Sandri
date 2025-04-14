#include "./headers/armas/HachaDoble.h"
#include <random>

HachaDoble::HachaDoble() : ArmaCombate("Hacha Doble", "Corte", "Acero", 20, 40, 5.0f) {
    // Generar GiroRapido aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    GiroRapido = distrib(gen);
}

int HachaDoble::getDanio() const {
    int danioBase = ArmaCombate::getDanio();
    if (GiroRapido) {
        return danioBase + 2; // Si tiene giro rápido, suma 2
    } else {
        return danioBase - 1; // Si no tiene giro rápido, resta 1
    }
}