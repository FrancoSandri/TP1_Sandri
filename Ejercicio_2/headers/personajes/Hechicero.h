#include "Mago.h"
#include <random>
#pragma once

using namespace std;

class Hechicero : public Mago {
private:
    bool auraMistica;
public:
    Hechicero();
    int getHP() const override;
};