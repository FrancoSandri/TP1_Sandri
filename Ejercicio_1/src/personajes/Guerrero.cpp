#include "../headers/personajes/Guerrero.h"
#include <iostream>
#include <algorithm> // Para std::max y std::min

using namespace std;

Guerrero::Guerrero(string n, int h, int f, int d, int v)
    : nombre(n), hp(std::max(0, h)), fuerza(max(0, f)), defensa(max(0, d)), 
      velocidad(max(0, v)), arma(nullptr) {
    // Validar que el nombre no esté vacío
    if (nombre.empty()) {
        nombre = "Guerrero sin nombre";
    }
}

std::string Guerrero::getNombre() const {
    return nombre;
}

int Guerrero::getHP() const {
    return hp;
}

void Guerrero::recibirDanio(int d) {
    hp-= d;
}

void Guerrero::mostrarEstado() const {
    cout << nombre << " [HP: " << getHP() 
              << ", Fuerza: " << fuerza 
              << ", Defensa: " << defensa 
              << ", Velocidad: " << velocidad;
    if (arma) {
        cout << ", Arma: " << arma->getNombre() 
                  << " (Daño: " << arma->getDanio() << ")";
    } else {
        cout << ", Sin arma";
    }
    cout << "]" << endl;
}

void Guerrero::atacar(IPersonaje& objetivo) {
    if (!arma) {
        cout << nombre << " no tiene arma para atacar a " 
                  << objetivo.getNombre() << "." << endl;
        return;
    }

    // Calcular daño: daño del arma + un factor basado en fuerza
    int danioBase = arma->getDanio();
    int danioExtra = fuerza / 2; // Escalar fuerza para balance
    int danioTotal = std::max(0, danioBase + danioExtra);

    // Simular probabilidad de acierto basada en velocidad (opcional)
    bool acierto = true; // Simplificado; podríamos usar velocidad aquí
    if (acierto) {
        cout << nombre << " ataca a " << objetivo.getNombre() 
                  << " con " << arma->getNombre() 
                  << " causando " << danioTotal << " de daño." << endl;
        arma->usar(); // Ejecutar efecto del arma
        objetivo.recibirDanio(danioTotal);
    } else {
        cout << nombre << " falla el ataque contra " 
                  << objetivo.getNombre() << "." << endl;
    }
}

void Guerrero::setArma(IArma* a) {
    arma = a;
}