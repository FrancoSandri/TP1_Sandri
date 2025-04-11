#include "ejercicio3.h"
#include "../Ejercicio_2/armas/ItemMagico.cpp"
#include "../Ejercicio_2/armas/ArmaCombate.cpp"
#include "../Ejercicio_2/personajes/Mago.cpp"
#include "../Ejercicio_2/personajes/Guerrero.cpp"
#include "../Ejercicio_2/personajes/Clases_Concretas_Personaje.h"
#include "../Ejercicio_2/armas/Clases_Concretas.h"
#include "ejercicio3.cpp"

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

    cout << "=== Personajes generados aleatoriamente === "<< endl ;
    for (auto& p : personajes) {
        p->mostrarEstado();
    }

    return 0;
}
