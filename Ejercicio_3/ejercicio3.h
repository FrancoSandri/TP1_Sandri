#ifndef EJERCICIO3_H
#define EJERCICIO3_H

#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Ejercicio_2/ejercicio2.h"

using namespace std;

enum class TipoArmaMagica {
    Baston,
    LibroHechizos,
    Pocion,
    Amuleto
};

enum class TipoArmaCombate {
    HachaSimple,
    HachaDoble,
    Espada,
    Lanza,
    Garrote
};

enum class TipoMago {
    Hechicero,
    Conjurador,
    Brujo,
    Nigromante
};

enum class TipoGuerrero {
    Barbaro,
    Paladin,
    Caballero,
    Mercenario,
    Gladiador
};

class PersonajeFactory {
public:
    static unique_ptr<Arma> crearArmaAleatoria();
    static unique_ptr<Personaje> crearMagoAleatorio();
    static unique_ptr<Personaje> crearGuerreroAleatorio();
    static void crearPersonajesArmados(vector<unique_ptr<Personaje>>& magos, vector<unique_ptr<Personaje>>& guerreros);
};

#endif
