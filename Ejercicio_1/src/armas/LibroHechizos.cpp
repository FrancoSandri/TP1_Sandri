#include "../headers/armas/LibroHechizos.h"

LibroHechizos::LibroHechizos():ItemMagico("Libro de Hechizos", "Fuego", "Tomo arcano", 20, 12, 1.2f) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    esAntiguo = distrib(gen);
}