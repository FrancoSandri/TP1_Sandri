// ================= armas/Baston.h =================
#ifndef CLASES_CONCRETAS_H
#define CLASES_CONCRETAS_H
#include "ItemMagico.h"

class Baston : public ItemMagico {
public:
    Baston() : ItemMagico("Bastón", "Trueno", "Antiguo bastón mágico", 25, 10, 1.5f) {}
};


class LibroHechizos : public ItemMagico {
public:
    LibroHechizos() : ItemMagico("Libro de Hechizos", "Fuego", "Tomo arcano", 30, 12, 1.2f) {}
};


class Pocion : public ItemMagico {
public:
    Pocion() : ItemMagico("Poción", "Curación", "Frasco sanador", 15, 5, 0.5f) {}
};


class Amuleto : public ItemMagico {
public:
    Amuleto() : ItemMagico("Amuleto", "Oscuridad", "Amuleto maldito", 20, 8, 0.8f) {}
};


#include "ArmaCombate.h"

class HachaSimple : public ArmaCombate {
public:
    HachaSimple() : ArmaCombate("Hacha Simple", "Corte", "Hierro", 20, 50, 3.0f) {}
};


class HachaDoble : public ArmaCombate {
public:
    HachaDoble() : ArmaCombate("Hacha Doble", "Corte", "Acero", 30, 40, 5.0f) {}
};


class Espada : public ArmaCombate {
public:
    Espada() : ArmaCombate("Espada", "Corte", "Acero", 25, 60, 3.5f) {}
};


class Lanza : public ArmaCombate {
public:
    Lanza() : ArmaCombate("Lanza", "Perforante", "Madera", 22, 55, 4.0f) {}
};


class Garrote : public ArmaCombate {
public:
    Garrote() : ArmaCombate("Garrote", "Contundente", "Roble", 18, 70, 4.5f) {}
};

#endif
