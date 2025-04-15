#include "../headers/armas/HachaDoble.h"
#include <random>

HachaDoble::HachaDoble() : ArmaCombate("Hacha Doble", "Corte", "Acero", 20, 40, 5.0f) {
    int tipo = rand() % 2;
    GiroRapido = tipo;
    filo = GiroRapido ? filo + 5 : filo - 5;
}
