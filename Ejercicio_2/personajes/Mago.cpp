#include "Mago.h"
#include <iostream>

Mago::Mago(string n, int h, int m, int i, int s) : nombre(n), hp(h), mana(m), inteligencia(i), sabiduria(s), arma(nullptr) {}
string Mago::getNombre() const { return nombre; }
int Mago::getHP() const { return hp; }
void Mago::recibirDanio(int d) { hp -= d; }
void Mago::mostrarEstado() const {
    cout << nombre << " [HP: " << hp << ", Mana: " << mana << "]\n";
}
void Mago::atacar(IPersonaje& o) {
    if (!arma) { cout << nombre << " no tiene arma.\n"; return; }
    cout << nombre << " ataca con " << arma->getNombre() << ".\n";
    arma->usar();
    mana -= 5;
    o.recibirDanio(arma->getDanio());
}
void Mago::setArma(IArma* a) { arma = a; }