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

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int numMagos = 3 + rand() % 5;
    int numGuerreros = 3 + rand() % 5;

    vector<unique_ptr<IPersonaje>> personajes;
    vector<unique_ptr<IArma>> armas;

    for (int i = 0; i < numMagos; ++i) {
        auto mago = PersonajeFactory::crearMagoRandom();
        IArma* arma = PersonajeFactory::crearArmaRandom();
        mago->setArma(arma);
        personajes.emplace_back(move(mago));
        armas.emplace_back(arma);
    }

    for (int i = 0; i < numGuerreros; ++i) {
        auto guerrero = PersonajeFactory::crearGuerreroRandom();
        IArma* arma = PersonajeFactory::crearArmaRandom();
        guerrero->setArma(arma);
        personajes.emplace_back(move(guerrero));
        armas.emplace_back(arma);
    }

    cout << "Personajes generados aleatoriamente."<< endl ;
    for (auto& p : personajes) {
        p->mostrarEstado();
    }

    return 0;
}
