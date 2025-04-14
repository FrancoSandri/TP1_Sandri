#include "Guerrero.h"
#include <random>
#pragma once

using namespace std;

class Caballero : public Guerrero {
private:
    bool honorInquebrantable;
public:
    Caballero();
    int getHP() const override;
};