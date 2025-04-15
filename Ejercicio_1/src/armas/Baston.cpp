#include "../headers/armas/Baston.h"
#include <random>

Baston::Baston() : ItemMagico("Bastón", "Trueno", "Antiguo bastón mágico", 15, 10, 1.5f) {
    int tipo = rand() % 2;
    tienePinchos = tipo;
    poder = tienePinchos ? poder + 5 : poder - 5;
}