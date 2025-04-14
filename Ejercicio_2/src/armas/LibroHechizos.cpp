#include "../headers/armas/LibroHechizos.h"

LibroHechizos::LibroHechizos():ItemMagico("Libro de Hechizos", "Fuego", "Tomo arcano", 20, 12, 1.2f) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esAntiguo = distrib(gen);
}

int LibroHechizos::getDanio() const {
    int danioBase = ItemMagico::getDanio();
    if (esAntiguo) {
        return danioBase + 2; // Si es antiguo, suma 2
    } else {
        return danioBase - 1; // Si no es antiguo, resta 1
    }
}