#include "../headers/armas/Pocion.h"
#include <random>

Pocion::Pocion() : ItemMagico("Pocion", "Luz", "Pocion magica", 10, 5, 0.5f) {
    // Generar esCurativa aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esCurativa = distrib(gen);
}

int Pocion::getDanio() const {
    int danioBase = ItemMagico::getDanio();
    if (esCurativa) {
        return danioBase + 2; // Si es curativa, suma 2
    } else {
        return danioBase - 1; // Si no es curativa, resta 1
    }
}