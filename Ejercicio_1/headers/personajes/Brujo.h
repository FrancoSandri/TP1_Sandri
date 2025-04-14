#include "Mago.h"
#include <random>
#pragma once

using namespace std;

class Brujo : public Mago {
private:
    bool pactoDemoniaco;
public:
    Brujo();
    int getHP() const override;
};