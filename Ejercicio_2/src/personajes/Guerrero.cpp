#include "../headers/personajes/Guerrero.h"
#include <iostream>

Guerrero::Guerrero(string n, int h, int f, int d, int v) : nombre(n), hp(h), fuerza(f), defensa(d), velocidad(v), arma(nullptr) {}
string Guerrero::getNombre() const { return nombre; }
int Guerrero::getHP() const { return hp; }
void Guerrero::recibirDanio(int d) { hp -= d; }
void Guerrero::mostrarEstado() const {
    cout << nombre << " [HP: " << hp << ", Fuerza: " << fuerza << "]\n";
}
void Guerrero::atacar(IPersonaje& o) {
    if (!arma) { std::cout << nombre << " no tiene arma.\n"; return; }
    cout << nombre << " ataca con " << arma->getNombre() << ".\n";
    arma->usar();
    o.recibirDanio(arma->getDanio() + fuerza);
}
void Guerrero::setArma(IArma* a) { arma = a; }