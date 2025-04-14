#include "../headers/armas/Baston.h"
#include <random>

Baston::Baston() : ItemMagico("Bastón", "Trueno", "Antiguo bastón mágico", 15, 10, 1.5f) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    tienePinchos = distrib(gen);
}

int Baston::getDanio() const {
    int danioBase = ItemMagico::getDanio();
    if (tienePinchos) {
        return danioBase + 2; // Si tiene pinchos, suma 2
    } else {
        return danioBase - 1; // Si no tiene pinchos, resta 1
    }
}