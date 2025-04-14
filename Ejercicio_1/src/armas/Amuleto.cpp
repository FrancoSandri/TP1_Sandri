#include "../headers/armas/Amuleto.h"
#include <random>

Amuleto::Amuleto() : ItemMagico("Amuleto", "Oscuridad", "Amuleto maldito", 18, 8, 0.8f) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esMaldito = distrib(gen);
}