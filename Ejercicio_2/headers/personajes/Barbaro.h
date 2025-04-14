#include "Guerrero.h"
#include <random>
#pragma once

using namespace std;

class Barbaro : public Guerrero {
private:
    bool furiaSalvaje;
public:
    Barbaro();
    int getHP() const override;
};