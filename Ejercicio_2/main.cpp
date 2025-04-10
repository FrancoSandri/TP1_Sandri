#include <iostream>
#include <vector>
#include <memory>

#include "armas/Clases_concretas.h"
#include "armas/ItemMagico.cpp"
#include "armas/ArmaCombate.cpp"
#include "personajes/Mago.cpp"
#include "personajes/Guerrero.cpp"
#include "personajes/Clases_Concretas_Personaje.h"

int main() {
    vector<unique_ptr<IPersonaje>> personajes;

    // Crear magos
    personajes.emplace_back(make_unique<Hechicero>());
    personajes.emplace_back(make_unique<Conjurador>());
    personajes.emplace_back(make_unique<Brujo>());
    personajes.emplace_back(make_unique<Nigromante>());

    // Crear guerreros
    personajes.emplace_back(make_unique<Barbaro>());
    personajes.emplace_back(make_unique<Paladin>());
    personajes.emplace_back(make_unique<Caballero>());
    personajes.emplace_back(make_unique<Mercenario>());
    personajes.emplace_back(make_unique<Gladiador>());

    // Armas mágicas
    vector<unique_ptr<IArma>> armas;
    
    armas.emplace_back(make_unique<Baston>());
    armas.emplace_back(make_unique<LibroHechizos>());
    armas.emplace_back(make_unique<Pocion>());
    armas.emplace_back(make_unique<Amuleto>());

    // Armas físicas
    armas.emplace_back(make_unique<HachaSimple>());
    armas.emplace_back(make_unique<HachaDoble>());
    armas.emplace_back(make_unique<Espada>());
    armas.emplace_back(make_unique<Lanza>());
    armas.emplace_back(make_unique<Garrote>());

    // Asignar armas a personajes de forma secuencial
    for (size_t i = 0; i < personajes.size(); ++i) {
        personajes[i]->setArma(armas[i % armas.size()].get());
    }

    // Mostrar estado
    for (auto& p : personajes) {
        p->mostrarEstado();
    }

    cout << "\nCombate de prueba entre los dos primeros personajes:" << endl;
    personajes[0]->atacar(*personajes[1]);
    personajes[1]->mostrarEstado();

    return 0;
}
