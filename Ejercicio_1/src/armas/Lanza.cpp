#include "../headers/armas/Lanza.h"
#include <random>

Lanza::Lanza() : ArmaCombate("Lanza", "Perforante", "Madera", 17, 55, 4.0f) {
    int tipo = rand() % 2;
    largoAlcance = tipo;
    filo = largoAlcance ? filo + 5 : filo - 5;
}