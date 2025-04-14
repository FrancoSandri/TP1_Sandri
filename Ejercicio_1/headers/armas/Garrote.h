#include "ArmaCombate.h"
#include <random>
#pragma once

using namespace std;

class Garrote : public ArmaCombate {
private:
    bool ataquePesado;
public:
    Garrote();
};