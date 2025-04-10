#include "ItemMagico.h"
#include <iostream>

ItemMagico::ItemMagico(std::string n, std::string e, std::string desc, int p, int m, float w)
    : nombre(n), elemento(e), descripcionMagica(desc), poder(p), manaCosto(m), peso(w) {}

string ItemMagico::getNombre() const { return nombre; }
int ItemMagico::getDanio() const { return poder; }
float ItemMagico::getPeso() const { return peso; }
string ItemMagico::getTipo() const { return "Magica: " + elemento; }
void ItemMagico::usar() { cout << nombre << " emite un aura de " << elemento << ".\n"; }