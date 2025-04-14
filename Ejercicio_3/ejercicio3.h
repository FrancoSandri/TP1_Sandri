#include <memory>
#include "../Ejercicio_2/headers/personajes/IPersonaje.h"
#include "../Ejercicio_2/headers/armas/IArma.h"
#pragma once

class PersonajeFactory {
public:
    static unique_ptr<IPersonaje> crearMagoRandom();
    static unique_ptr<IPersonaje> crearGuerreroRandom();
    static IArma* crearArmaRandom();
};