#include "Guerrero.h"
#include <random>
#pragma once

using namespace std;

class Gladiador : public Guerrero {
private:
    bool gloriaCombate;
public:
    Gladiador();
    int getHP() const override;
};