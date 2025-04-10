#ifndef IPERSONAJE_H
#define IPERSONAJE_H
#include <string>
#include "../armas/IArma.h"

using namespace std;

class IPersonaje {
public:
    virtual string getNombre() const = 0;
    virtual int getHP() const = 0;
    virtual void recibirDanio(int) = 0;
    virtual void mostrarEstado() const = 0;
    virtual void atacar(IPersonaje&) = 0;
    virtual void setArma(IArma*) = 0;
    virtual ~IPersonaje() = default;
};
#endif
