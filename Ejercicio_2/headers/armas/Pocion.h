#include "ItemMagico.h"
#pragma once

class Pocion : public ItemMagico {
    private:
        bool esCurativa;
    public:
        Pocion();
        int getDanio() const override;
    };