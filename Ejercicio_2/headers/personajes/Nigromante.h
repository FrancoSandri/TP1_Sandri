#include "Mago.h"
#include <random>
#pragma once

using namespace std;

class Nigromante : public Mago {
private:
    bool esenciaNecrotica;
public:
    Nigromante();
    int getHP() const override;
};