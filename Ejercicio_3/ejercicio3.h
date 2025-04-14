#pragma once

#include "../Ejercicio_1/headers/personajes/IPersonaje.h"
#include "../Ejercicio_1/headers/armas/IArma.h"
#include <iostream>

enum class Movimiento { FUERTE = 1, RAPIDO = 2, DEFENSA = 3 };

int resolverCombate(Movimiento p1, Movimiento p2);
void mostrarMenu(IPersonaje& j1, IArma* a1, IPersonaje& j2, IArma* a2);