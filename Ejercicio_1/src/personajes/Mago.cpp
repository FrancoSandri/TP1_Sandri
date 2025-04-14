#include "../headers/personajes/Mago.h"
#include <iostream>
#include <algorithm> // Para std::max y std::min

using namespace std;

Mago::Mago(string n, int h, int m, int i, int s)
    : nombre(n), hp(std::max(0, h)), mana(max(0, m)), 
      inteligencia(std::max(0, i)), sabiduria(max(0, s)), arma(nullptr) {
    // Validar que el nombre no esté vacío
    if (nombre.empty()) {
        nombre = "Mago sin nombre";
    }
}

string Mago::getNombre() const {
    return nombre;
}

int Mago::getHP() const {
    return hp;
}

void Mago::recibirDanio(int d) {
    // Usar sabiduría para reducir el daño (similar a defensa en Guerrero)
    hp -= d;
}

void Mago::mostrarEstado() const {
    cout << nombre << " [HP: " << getHP()
              << ", Mana: " << mana 
              << ", Inteligencia: " << inteligencia 
              << ", Sabiduría: " << sabiduria;
    if (arma) {
        cout << ", Arma: " << arma->getNombre() 
                  << " (Daño: " << arma->getDanio() << ")";
    } else {
        cout << ", Sin arma";
    }
    cout << "]" << endl;
}

void Mago::atacar(IPersonaje& objetivo) {
    if (!arma) {
        cout << nombre << " no tiene arma para atacar a " 
                  << objetivo.getNombre() << "." << endl;
        return;
    }

    // Costo de mana para atacar
    int costoMana = 5;
    // Reducir costo de mana basado en sabiduría (ejemplo: sabiduría=70 -> reduce 1)
    costoMana = std::max(1, costoMana - (sabiduria / 35));

    if (mana < costoMana) {
        cout << nombre << " no tiene suficiente maná para atacar a " 
                  << objetivo.getNombre() << "." << endl;
        return;
    }

    // Calcular daño: daño del arma + un factor basado en inteligencia
    int danioBase = arma->getDanio();
    int danioExtra = inteligencia / 4; // Escalar inteligencia para balance
    int danioTotal = max(0, danioBase + danioExtra);

    // Aplicar ataque
    mana -= costoMana;
    cout << nombre << " lanza un hechizo a " << objetivo.getNombre() 
              << " con " << arma->getNombre() 
              << " causando " << danioTotal << " de daño (usó " 
              << costoMana << " maná)." << endl;
    arma->usar(); // Ejecutar efecto del arma
    objetivo.recibirDanio(danioTotal);
}

void Mago::setArma(IArma* a) {
    arma = a;
}