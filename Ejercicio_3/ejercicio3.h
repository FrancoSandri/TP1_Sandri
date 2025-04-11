#pragma once
#include <memory>
#include "../Ejercicio_2/personajes/IPersonaje.h"
#include "../Ejercicio_2/armas/IArma.h"

class PersonajeFactory {
public:
    static unique_ptr<IPersonaje> crearMagoRandom();
    static unique_ptr<IPersonaje> crearGuerreroRandom();
    static IArma* crearArmaRandom();
};