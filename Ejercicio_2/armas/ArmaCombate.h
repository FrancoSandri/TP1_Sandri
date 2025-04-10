#ifndef ARMACOMBATE_H
#define ARMACOMBATE_H
#include "IArma.h"

using namespace std;

class ArmaCombate : public IArma {
protected:
    string nombre, tipo, material;
    int filo, durabilidad;
    float peso;
public:
    ArmaCombate(string nombre, string tipo, string material, int filo, int durabilidad, float peso);
    string getNombre() const override;
    int getDanio() const override;
    float getPeso() const override;
    string getTipo() const override;
    void usar() override;
};
#endif