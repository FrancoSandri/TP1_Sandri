#include "ItemMagico.h"
#pragma once

class Baston : public ItemMagico {
public:
    Baston() : ItemMagico("Bastón", "Trueno", "Antiguo bastón mágico", 15, 10, 1.5f) {}
};


class LibroHechizos : public ItemMagico {
public:
    LibroHechizos() : ItemMagico("Libro de Hechizos", "Fuego", "Tomo arcano", 20, 12, 1.2f) {}
};


class Pocion : public ItemMagico {
public:
    Pocion() : ItemMagico("Poción", "Curación", "Frasco sanador", 17, 5, 0.5f) {}
};


class Amuleto : public ItemMagico {
public:
    Amuleto() : ItemMagico("Amuleto", "Oscuridad", "Amuleto maldito", 18, 8, 0.8f) {}
};


#include "ArmaCombate.h"

class HachaSimple : public ArmaCombate {
public:
    HachaSimple() : ArmaCombate("Hacha Simple", "Corte", "Hierro", 10, 50, 3.0f) {}
};


class HachaDoble : public ArmaCombate {
public:
    HachaDoble() : ArmaCombate("Hacha Doble", "Corte", "Acero", 20, 40, 5.0f) {}
};


class Espada : public ArmaCombate {
public:
    Espada() : ArmaCombate("Espada", "Corte", "Acero", 12, 60, 3.5f) {}
};


class Lanza : public ArmaCombate {
public:
    Lanza() : ArmaCombate("Lanza", "Perforante", "Madera", 17, 55, 4.0f) {}
};


class Garrote : public ArmaCombate {
public:
    Garrote() : ArmaCombate("Garrote", "Contundente", "Roble", 15, 70, 4.5f) {}
};