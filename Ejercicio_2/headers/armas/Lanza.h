#include "ArmaCombate.h"
#include <random>
#pragma once

using namespace std;

class Lanza : public ArmaCombate {
private:
    bool largoAlcance;
public:
    Lanza();
    int getDanio() const override;
};