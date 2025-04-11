#ifndef GUERRERO_H
#define GUERRERO_H
#include "IPersonaje.h"
#pragma once

class Guerrero : public IPersonaje {
protected:
    string nombre;
    int hp, fuerza, defensa, velocidad;
    IArma* arma;
public:
    Guerrero(std::string nombre, int hp, int fuerza, int defensa, int velocidad);
    string getNombre() const override;
    int getHP() const override;
    void recibirDanio(int d) override;
    void mostrarEstado() const override;
    void atacar(IPersonaje& o) override;
    void setArma(IArma* a) override;
};
#endif