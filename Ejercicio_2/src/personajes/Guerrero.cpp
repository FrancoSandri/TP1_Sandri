#include "../headers/personajes/Guerrero.h"
#include <iostream>
#include <algorithm> // Para std::max y std::min

Guerrero::Guerrero(std::string n, int h, int f, int d, int v)
    : nombre(n), hp(std::max(0, h)), fuerza(std::max(0, f)), defensa(std::max(0, d)), 
      velocidad(std::max(0, v)), arma(nullptr) {
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
    // Aplicar defensa para reducir el daño
    int danioEfectivo = std::max(0, d - defensa);
    hp = std::max(0, hp - danioEfectivo);
}

void Guerrero::mostrarEstado() const {
    std::cout << nombre << " [HP: " << getHP() 
              << ", Fuerza: " << fuerza 
              << ", Defensa: " << defensa 
              << ", Velocidad: " << velocidad;
    if (arma) {
        std::cout << ", Arma: " << arma->getNombre() 
                  << " (Daño: " << arma->getDanio() << ")";
    } else {
        std::cout << ", Sin arma";
    }
    std::cout << "]" << std::endl;
}

void Guerrero::atacar(IPersonaje& objetivo) {
    if (!arma) {
        std::cout << nombre << " no tiene arma para atacar a " 
                  << objetivo.getNombre() << "." << std::endl;
        return;
    }

    // Calcular daño: daño del arma + un factor basado en fuerza
    int danioBase = arma->getDanio();
    int danioExtra = fuerza / 2; // Escalar fuerza para balance
    int danioTotal = std::max(0, danioBase + danioExtra);

    // Simular probabilidad de acierto basada en velocidad (opcional)
    bool acierto = true; // Simplificado; podríamos usar velocidad aquí
    if (acierto) {
        std::cout << nombre << " ataca a " << objetivo.getNombre() 
                  << " con " << arma->getNombre() 
                  << " causando " << danioTotal << " de daño." << std::endl;
        arma->usar(); // Ejecutar efecto del arma
        objetivo.recibirDanio(danioTotal);
    } else {
        std::cout << nombre << " falla el ataque contra " 
                  << objetivo.getNombre() << "." << std::endl;
    }
}

void Guerrero::setArma(IArma* a) {
    arma = a;
}