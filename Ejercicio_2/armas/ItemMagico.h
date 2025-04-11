#ifndef ITEMMAGICO_H
#define ITEMMAGICO_H
#include "IArma.h"
#pragma once

using namespace std;

class ItemMagico : public IArma {
protected:
    string nombre, elemento, descripcionMagica;
    int poder, manaCosto;
    float peso;
public:
    ItemMagico(string nombre, string elemento, string descripcionMagica, int poder, int manaCosto, float peso);
    string getNombre() const override;
    int getDanio() const override;
    float getPeso() const override;
    string getTipo() const override;
    void usar() override;
};
#endif