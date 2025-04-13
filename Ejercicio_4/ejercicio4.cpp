#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "../Ejercicio_3/ejercicio3.h"
#include "ejercicio4.h"
#include "../Ejercicio_2/armas/Clases_Concretas.h"
#include "../Ejercicio_2/personajes/Clases_Concretas_Personaje.h"

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
            j2.recibirDanio(a1->getDanio());
            cout << j1.getNombre() << " gana la ronda y hace " << a1->getDanio() << " puntos de daño." << endl;
        } else if (resultado == 2) {
            j1.recibirDanio(a2->getDanio());
            cout << j2.getNombre() << " gana la ronda y hace " << a2->getDanio() << " puntos de daño." << endl;
        } else {
            cout << "Empate. Nadie recibe daño." << endl;
        }
    }

    cout << "\nFin de la batalla!\n";
    if (j1.getHP() <= 0) cout << j1.getNombre() << " ha sido derrotado." << endl;
    if (j2.getHP() <= 0) cout << j2.getNombre() << " ha sido derrotado." << endl;
}