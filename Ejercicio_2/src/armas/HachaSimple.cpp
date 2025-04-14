#include "../headers/armas/HachaSimple.h"
#include <random>

HachaSimple::HachaSimple() : ArmaCombate("Hacha Simple", "Corte", "Hierro", 10, 50, 3.0f) {
    // Generar esDeMadera aleatoriamente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esDeMadera = distrib(gen);
}

int HachaSimple::getDanio() const {
    int danioBase = ArmaCombate::getDanio();
    if (esDeMadera) {
        return danioBase + 2; // Si es de madera, suma 2
    } else {
        return danioBase - 1; // Si no es de madera, resta 1
    }
}