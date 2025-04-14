#include "../Ejercicio_1/headers/personajes/IPersonaje.h"
#include "../Ejercicio_1/headers/armas/IArma.h"
#include <memory>
#pragma once

class PersonajeFactory {
public:
    static unique_ptr<IPersonaje> crearMagoRandom();
    static unique_ptr<IPersonaje> crearGuerreroRandom();
    static IArma* crearArmaRandom();
};