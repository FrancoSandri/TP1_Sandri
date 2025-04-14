#include "Guerrero.h"
#include <random>
#pragma once

using namespace std;

class Paladin : public Guerrero {
private:
    bool bendicionDivina;
public:
    Paladin();
    int getHP() const override;
};