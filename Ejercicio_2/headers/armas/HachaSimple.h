#include "ArmaCombate.h"
#include <random>
#pragma once

using namespace std;

class HachaSimple : public ArmaCombate {
private:
    bool esDeMadera;
public:
    HachaSimple();
    int getDanio() const override;
};