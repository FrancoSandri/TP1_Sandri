#include "Guerrero.h"
#include <random>
#pragma once

using namespace std;

class Mercenario : public Guerrero {
private:
    bool instintoSupervivencia;
public:
    Mercenario();
    int getHP() const override;
};