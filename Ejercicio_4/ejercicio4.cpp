// ===================== Problema 4 =====================
// Simulación de batalla estilo piedra-papel-tijera entre personajes

#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "../Ejercicio_3/ejercicio3.h"
#include "ejercicio4.h"
#include "../Ejercicio_2/armas/Clases_Concretas.h"
#include "../Ejercicio_2/personajes/Clases_Concretas_Personaje.h"
#include "../Ejercicio_2/armas/ItemMagico.cpp"
#include "../Ejercicio_2/armas/ArmaCombate.cpp"
#include "../Ejercicio_2/personajes/Mago.cpp"
#include "../Ejercicio_2/personajes/Guerrero.cpp"

int resolverCombate(Movimiento p1, Movimiento p2) {
    if (p1 == p2) return 0;
    if ((p1 == Movimiento::FUERTE && p2 == Movimiento::RAPIDO) ||
        (p1 == Movimiento::RAPIDO && p2 == Movimiento::DEFENSA) ||
        (p1 == Movimiento::DEFENSA && p2 == Movimiento::FUERTE)) {
        return 1;
    }
    return 2;
}

void mostrarMenu(IPersonaje& j1, IArma* a1, IPersonaje& j2, IArma* a2) {
    while (j1.getHP() > 0 && j2.getHP() > 0) {
        cout << "\n" << j1.getNombre() << " tiene " << j1.getHP() << " HP" << endl;
        cout << j2.getNombre() << " tiene " << j2.getHP() << " HP" << endl;
        cout << "\nSu opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";

        int opcion;
        cin >> opcion;
        if (opcion < 1 || opcion > 3) continue;

        Movimiento m1 = static_cast<Movimiento>(opcion);
        Movimiento m2 = static_cast<Movimiento>(1 + rand() % 3);

        int resultado = resolverCombate(m1, m2);

        cout << j1.getNombre() << " ataca con " << a1->getNombre() << " y elige opción " << static_cast<int>(m1) << endl;
        cout << j2.getNombre() << " ataca con " << a2->getNombre() << " y elige opción " << static_cast<int>(m2) << endl;

        if (resultado == 1) {
            j2.recibirDanio(10);
            cout << j1.getNombre() << " gana la ronda y hace 10 puntos de daño." << endl;
        } else if (resultado == 2) {
            j1.recibirDanio(10);
            cout << j2.getNombre() << " gana la ronda y hace 10 puntos de daño." << endl;
        } else {
            cout << "Empate. Nadie recibe daño." << endl;
        }
    }

    cout << "\n*** Fin de la batalla ***\n";
    if (j1.getHP() <= 0) cout << j1.getNombre() << " ha sido derrotado." << endl;
    if (j2.getHP() <= 0) cout << j2.getNombre() << " ha sido derrotado." << endl;
}

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

    auto jugador2 = PersonajeFactory::crearMagoRandom();
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
