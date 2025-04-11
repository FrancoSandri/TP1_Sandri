#ifndef EJERCICIO_4_H
#define EJERCICIO_4_H
#pragma once

#include "../Ejercicio_2/personajes/IPersonaje.h"
#include <iostream>

enum class Movimiento { FUERTE = 1, RAPIDO = 2, DEFENSA = 3 };

int resolverCombate(Movimiento p1, Movimiento p2);
void mostrarMenu(IPersonaje& j1, IPersonaje& j2);

#endif