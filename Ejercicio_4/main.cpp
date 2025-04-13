#include "ejercicio4.h"
#include "ejercicio4.cpp"
#include "../Ejercicio_3/ejercicio3.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Elija su personaje: \n1. Caballero\n2. Paladin\n3. Barbaro\n4. Mercenario\n5. Gladiador\n6. Conjurador\n7. Hechicero\n8. Nigromante\n9. Brujo\nOpcion: ";
    int opcionPersonaje;
    cin >> opcionPersonaje;

    cout << "Elija su arma: \n1. Espada\n2. Lanza\n3. HachaSimple\n4. HachaDoble\n5. Garrote\n6. Libro de Hechizos\n7. Baston\n8. Amuleto\n9. Pocion\nOpcion: ";
    int opcionArma;
    cin >> opcionArma;

    unique_ptr<IPersonaje> jugador1;
    switch (opcionPersonaje) {
        case 1: jugador1 = make_unique<Caballero>(); break;
        case 2: jugador1 = make_unique<Paladin>(); break;
        case 3: jugador1 = make_unique<Barbaro>(); break;
        case 4: jugador1 = make_unique<Mercenario>(); break;
        case 5: jugador1 = make_unique<Gladiador>(); break;
        case 6: jugador1 = make_unique<Conjurador>(); break;
        case 7: jugador1 = make_unique<Hechicero>(); break;
        case 8: jugador1 = make_unique<Nigromante>();break;
        case 9: jugador1 = make_unique<Brujo>();break;
        //caso default, seteo un caballeto
        default: jugador1 = make_unique<Caballero>(); break;
    }

    IArma* arma1 = nullptr;
    switch (opcionArma) {
        case 1: arma1 = new Espada(); break;
        case 2: arma1 = new Lanza(); break;
        case 3: arma1 = new HachaSimple(); break;
        case 4: arma1 = new HachaDoble(); break;
        case 5: arma1 = new Garrote(); break;
        case 6: arma1 = new LibroHechizos(); break;
        case 7: arma1 = new Baston(); break;
        case 8: arma1 = new Amuleto(); break;
        case 9: arma1 = new Pocion(); break;
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
