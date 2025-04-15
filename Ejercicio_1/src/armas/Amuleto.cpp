#include "../headers/armas/Amuleto.h"
#include <random>

Amuleto::Amuleto() : ItemMagico("Amuleto", "Oscuridad", "Amuleto maldito", 18, 8, 0.8f) {
    int tipo = rand() % 2;
    esMaldito = tipo;
    poder = esMaldito ? poder + 5 : poder - 5;
}