#pragma once
#include "IPersonaje.h"

class Mago : public IPersonaje {
protected:
    string nombre;
    int hp, mana, inteligencia, sabiduria;
    IArma* arma;
public:
    Mago(string nombre, int hp, int mana, int inteligencia, int sabiduria);
    string getNombre() const override;
    int getHP() const override;
    void recibirDanio(int d) override;
    void mostrarEstado() const override;
    void atacar(IPersonaje& o) override;
    void setArma(IArma* a) override;
};
