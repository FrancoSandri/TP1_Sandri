#include "../headers/armas/HachaSimple.h"
#include <random>

HachaSimple::HachaSimple() : ArmaCombate("Hacha Simple", "Corte", "Hierro", 10, 50, 3.0f) {
    int tipo = rand() % 2;
    esDeMadera = tipo;
    filo = esDeMadera ? filo + 5 : filo - 5;
}
