#pragma once

#include <string>
using namespace std;

class IArma {
public:
    virtual string getNombre() const = 0;
    virtual int getDanio() const = 0;
    virtual float getPeso() const = 0;
    virtual string getTipo() const = 0;
    virtual void usar() = 0;
    virtual ~IArma() = default;
};
