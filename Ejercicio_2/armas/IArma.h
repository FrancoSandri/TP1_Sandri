#ifndef IARMA_H
#define IARMA_H
#include <string>
#pragma once

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
#endif
