#include "ItemMagico.h"
#include <random>
#pragma once

using namespace std;

class Amuleto : public ItemMagico {
private:
    bool esMaldito;
public:
    Amuleto();
    int getDanio() const override;
};