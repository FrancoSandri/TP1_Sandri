#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "ejercicio2.h"

#include "../Ejercicio_1/headers/personajes/Mago.h"
#include "../Ejercicio_1/headers/personajes/Guerrero.h"
#include "../Ejercicio_1/headers/personajes/Hechicero.h"
#include "../Ejercicio_1/headers/personajes/Conjurador.h"
#include "../Ejercicio_1/headers/personajes/Brujo.h"
#include "../Ejercicio_1/headers/personajes/Nigromante.h"
#include "../Ejercicio_1/headers/personajes/Barbaro.h"
#include "../Ejercicio_1/headers/personajes/Paladin.h"
#include "../Ejercicio_1/headers/personajes/Caballero.h"
#include "../Ejercicio_1/headers/personajes/Mercenario.h"
#include "../Ejercicio_1/headers/personajes/Gladiador.h"

#include "../Ejercicio_1/headers/armas/ItemMagico.h"
#include "../Ejercicio_1/headers/armas/ArmaCombate.h"
#include "../Ejercicio_1/headers/armas/Baston.h"
#include "../Ejercicio_1/headers/armas/LibroHechizos.h"
#include "../Ejercicio_1/headers/armas/Pocion.h"
#include "../Ejercicio_1/headers/armas/Amuleto.h"
#include "../Ejercicio_1/headers/armas/HachaSimple.h"
#include "../Ejercicio_1/headers/armas/HachaDoble.h"
#include "../Ejercicio_1/headers/armas/Espada.h"
#include "../Ejercicio_1/headers/armas/Lanza.h"
#include "../Ejercicio_1/headers/armas/Garrote.h"


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