#include "ejercicio4.h"
#include "ejercicio4.cpp"
#include "../Ejercicio_3/ejercicio3.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Elija su personaje: \n1. Caballero\n2. Paladin\n3. Barbaro\n4. Mercenario\n5. Gladiador\nOpcion: ";
    int opcionPersonaje;
    cin >> opcionPersonaje;

    cout << "Elija su arma: \n1. Espada\n2. Lanza\n3. HachaSimple\n4. HachaDoble\n5. Garrote\nOpcion: ";
    int opcionArma;
    cin >> opcionArma;

    unique_ptr<IPersonaje> jugador1;
    switch (opcionPersonaje) {
        case 1: jugador1 = make_unique<Caballero>(); break;
        case 2: jugador1 = make_unique<Paladin>(); break;
        case 3: jugador1 = make_unique<Barbaro>(); break;
        case 4: jugador1 = make_unique<Mercenario>(); break;
        case 5: jugador1 = make_unique<Gladiador>(); break;
        default: jugador1 = make_unique<Caballero>(); break;
    }

    IArma* arma1 = nullptr;
    switch (opcionArma) {
        case 1: arma1 = new Espada(); break;
        case 2: arma1 = new Lanza(); break;
        case 3: arma1 = new HachaSimple(); break;
        case 4: arma1 = new HachaDoble(); break;
        case 5: arma1 = new Garrote(); break;
        default: arma1 = new Espada(); break;
    }

    auto jugador2 = (rand() % 2 == 0)
    ? PersonajeFactory::crearMagoRandom()
    : PersonajeFactory::crearGuerreroRandom();
    IArma* arma2 = PersonajeFactory::crearArmaRandom();

    jugador1->setArma(arma1);
    jugador2->setArma(arma2);

    cout << "\nEl combate es entre: " << jugador1->getNombre()
              << " (" << arma1->getNombre() << ") y "
              << jugador2->getNombre() << " (" << arma2->getNombre() << ")\n";

    mostrarMenu(*jugador1, arma1, *jugador2, arma2);

    delete arma1;
    delete arma2;

    return 0;
}
