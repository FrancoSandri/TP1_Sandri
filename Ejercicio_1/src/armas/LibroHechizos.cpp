#include "../headers/armas/LibroHechizos.h"

LibroHechizos::LibroHechizos():ItemMagico("Libro de Hechizos", "Fuego", "Tomo arcano", 20, 12, 1.2f) {
    int tipo = rand() % 2;
    esAntiguo = tipo;
    poder = esAntiguo ? poder + 5 : poder - 5;
}