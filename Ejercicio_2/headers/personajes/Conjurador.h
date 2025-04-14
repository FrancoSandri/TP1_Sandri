#include "Mago.h"
#include <random>
#pragma once

using namespace std;

class Conjurador : public Mago {
private:
    bool enlaceEter;
public:
    Conjurador();
    int getHP() const override;
};