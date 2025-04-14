#include <iostream>
#include <vector>
#include <memory>

#include "../headers/personajes/IPersonaje.h"
#include "../headers/personajes/Mago.h"
#include "../headers/personajes/Guerrero.h"
#include "../headers/personajes/Hechicero.h"
#include "../headers/personajes/Conjurador.h"
#include "../headers/personajes/Brujo.h"
#include "../headers/personajes/Nigromante.h"
#include "../headers/personajes/Barbaro.h"
#include "../headers/personajes/Paladin.h"
#include "../headers/personajes/Caballero.h"
#include "../headers/personajes/Mercenario.h"
#include "../headers/personajes/Gladiador.h"

#include "../headers/armas/IArma.h"
#include "../headers/armas/ItemMagico.h"
#include "../headers/armas/ArmaCombate.h"
#include "../headers/armas/Baston.h"
#include "../headers/armas/LibroHechizos.h"
#include "../headers/armas/Pocion.h"
#include "../headers/armas/Amuleto.h"
#include "../headers/armas/HachaSimple.h"
#include "../headers/armas/HachaDoble.h"
#include "../headers/armas/Espada.h"
#include "../headers/armas/Lanza.h"
#include "../headers/armas/Garrote.h"

using namespace std;

int main() {
    // Vector para almacenar personajes
    vector<std::unique_ptr<IPersonaje>> personajes;

    // Crear magos
    personajes.emplace_back(std::make_unique<Hechicero>());
    personajes.emplace_back(std::make_unique<Conjurador>());
    personajes.emplace_back(std::make_unique<Brujo>());
    personajes.emplace_back(std::make_unique<Nigromante>());

    // Crear guerreros
    personajes.emplace_back(std::make_unique<Barbaro>());
    personajes.emplace_back(std::make_unique<Paladin>());
    personajes.emplace_back(std::make_unique<Caballero>());
    personajes.emplace_back(std::make_unique<Mercenario>());
    personajes.emplace_back(std::make_unique<Gladiador>());

    // Vector para almacenar armas
    vector<std::unique_ptr<IArma>> armas;

    // Armas mágicas
    armas.emplace_back(std::make_unique<Baston>());
    armas.emplace_back(std::make_unique<LibroHechizos>());
    armas.emplace_back(std::make_unique<Pocion>());
    armas.emplace_back(std::make_unique<Amuleto>());

    // Armas físicas
    armas.emplace_back(std::make_unique<HachaSimple>());
    armas.emplace_back(std::make_unique<HachaDoble>());
    armas.emplace_back(std::make_unique<Espada>());
    armas.emplace_back(std::make_unique<Lanza>());
    armas.emplace_back(std::make_unique<Garrote>());

    // Asignar armas a personajes de forma secuencial
    for (size_t i = 0; i < personajes.size(); ++i) {
        personajes[i]->setArma(armas[i % armas.size()].get());
    }

    // Mostrar estado inicial de todos los personajes
    cout << "Estado inicial de los personajes:\n" << endl;
    for (const auto& p : personajes) {
        p->mostrarEstado();
    }

    // Simular un combate de prueba entre todos los personajes
    cout << "\n=== Combate de prueba ===\n" << endl;
    for (size_t i = 0; i < personajes.size() - 1; i += 2) {
        cout << personajes[i]->getNombre() << " ataca a " << personajes[i + 1]->getNombre() << ":\n";
        personajes[i]->atacar(*personajes[i + 1]);
        cout << "Estado de " << personajes[i + 1]->getNombre() << " después del ataque:\n";
        personajes[i + 1]->mostrarEstado();
        cout << endl;
    }

    // Mostrar estado final de todos los personajes
    cout << "\nEstado final de los personajes:\n" << endl;
    for (const auto& p : personajes) {
        p->mostrarEstado();
    }

    return 0;
}