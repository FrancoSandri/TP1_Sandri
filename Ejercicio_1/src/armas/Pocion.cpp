#include "../headers/armas/Pocion.h"
#include <random>

Pocion::Pocion() : ItemMagico("Pocion", "Luz", "Pocion magica", 10, 5, 0.5f) {
    int tipo = rand() % 2;
    esCurativa = tipo;
    poder = esCurativa ? poder + 5 : poder - 5;
}