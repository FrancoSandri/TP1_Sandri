#include "ejercicio3.h"

// Para obtener un número aleatorio entre a y b (incluidos)
int randomInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

unique_ptr<Arma> PersonajeFactory::crearArmaAleatoria() {
    int tipoTotal = randomInt(0, 8); // 4 mágicas + 5 combate
    if (tipoTotal <= 3) { // Armas mágicas
        TipoArmaMagica tipo = static_cast<TipoArmaMagica>(tipoTotal);
        switch (tipo) {
            case TipoArmaMagica::Baston: return make_unique<Baston>();
            case TipoArmaMagica::LibroHechizos: return make_unique<LibroHechizos>();
            case TipoArmaMagica::Pocion: return make_unique<Pocion>();
            case TipoArmaMagica::Amuleto: return make_unique<Amuleto>();
        }
    } else { // Armas de combate
        TipoArmaCombate tipo = static_cast<TipoArmaCombate>(tipoTotal - 4);
        switch (tipo) {
            case TipoArmaCombate::HachaSimple: return make_unique<HachaSimple>();
            case TipoArmaCombate::HachaDoble: return make_unique<HachaDoble>();
            case TipoArmaCombate::Espada: return make_unique<Espada>();
            case TipoArmaCombate::Lanza: return make_unique<Lanza>();
            case TipoArmaCombate::Garrote: return make_unique<Garrote>();
        }
    }
    return nullptr;
}

unique_ptr<Personaje> PersonajeFactory::crearMagoAleatorio() {
    TipoMago tipo = static_cast<TipoMago>(randomInt(0, 3));
    string nombre = "Mago_" + to_string(rand());
    switch (tipo) {
        case TipoMago::Hechicero: return make_unique<Hechicero>(nombre);
        case TipoMago::Conjurador: return make_unique<Conjurador>(nombre);
        case TipoMago::Brujo: return make_unique<Brujo>(nombre);
        case TipoMago::Nigromante: return make_unique<Nigromante>(nombre);
    }
    return nullptr;
}

unique_ptr<Personaje> PersonajeFactory::crearGuerreroAleatorio() {
    TipoGuerrero tipo = static_cast<TipoGuerrero>(randomInt(0, 4));
    string nombre = "Guerrero_" + to_string(rand());
    switch (tipo) {
        case TipoGuerrero::Barbaro: return make_unique<Barbaro>(nombre);
        case TipoGuerrero::Paladin: return make_unique<Paladin>(nombre);
        case TipoGuerrero::Caballero: return make_unique<Caballero>(nombre);
        case TipoGuerrero::Mercenario: return make_unique<Mercenario>(nombre);
        case TipoGuerrero::Gladiador: return make_unique<Gladiador>(nombre);
    }
    return nullptr;
}

void PersonajeFactory::crearPersonajesArmados(vector<unique_ptr<Personaje>>& magos, vector<unique_ptr<Personaje>>& guerreros) {
    srand(static_cast<unsigned int>(time(nullptr))); // semilla para aleatoriedad

    int cantidadMagos = randomInt(3, 7);
    int cantidadGuerreros = randomInt(3, 7);

    for (int i = 0; i < cantidadMagos; ++i) {
        auto mago = crearMagoAleatorio();
        int cantidadArmas = randomInt(0, 2);
        for (int j = 0; j < cantidadArmas; ++j) {
            mago->equiparArma(crearArmaAleatoria().release());
        }
        magos.push_back(move(mago));
    }

    for (int i = 0; i < cantidadGuerreros; ++i) {
        auto guerrero = crearGuerreroAleatorio();
        int cantidadArmas = randomInt(0, 2);
        for (int j = 0; j < cantidadArmas; ++j) {
            guerrero->equiparArma(crearArmaAleatoria().release());
        }
        guerreros.push_back(move(guerrero));
    }
}

int main() {
    vector<unique_ptr<Personaje>> magos;
    vector<unique_ptr<Personaje>> guerreros;

    PersonajeFactory::crearPersonajesArmados(magos, guerreros);

    for (const auto& mago : magos) {
        cout << mago->getNombre() << ": " << mago->usarArma() << endl;
    }

    for (const auto& guerrero : guerreros) {
        cout << guerrero->getNombre() << ": " << guerrero->usarArma() << endl;
    }

    return 0;
}