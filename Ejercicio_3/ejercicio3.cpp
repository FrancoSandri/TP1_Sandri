#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "ejercicio3.h"
#include "../Ejercicio_2/armas/ItemMagico.cpp"
#include "../Ejercicio_2/armas/ArmaCombate.cpp"
#include "../Ejercicio_2/personajes/Mago.cpp"
#include "../Ejercicio_2/personajes/Guerrero.cpp"
#include "../Ejercicio_2/personajes/Clases_Concretas_Personaje.h"
#include "../Ejercicio_2/armas/Clases_Concretas.h"

unique_ptr<IPersonaje> PersonajeFactory::crearMagoRandom() {
    int tipo = rand() % 4;
    switch (tipo) {
        case 0: return make_unique<Hechicero>();
        case 1: return make_unique<Conjurador>();
        case 2: return make_unique<Brujo>();
        default: return make_unique<Nigromante>();
    }
}

unique_ptr<IPersonaje> PersonajeFactory::crearGuerreroRandom() {
    int tipo = rand() % 5;
    switch (tipo) {
        case 0: return make_unique<Barbaro>();
        case 1: return make_unique<Paladin>();
        case 2: return make_unique<Caballero>();
        case 3: return make_unique<Mercenario>();
        default: return make_unique<Gladiador>();
    }
}

IArma* PersonajeFactory::crearArmaRandom() {
    int tipo = rand() % 9;
    switch (tipo) {
        case 0: return new Baston();
        case 1: return new LibroHechizos();
        case 2: return new Pocion();
        case 3: return new Amuleto();
        case 4: return new HachaSimple();
        case 5: return new HachaDoble();
        case 6: return new Espada();
        case 7: return new Lanza();
        default: return new Garrote();
    }
}