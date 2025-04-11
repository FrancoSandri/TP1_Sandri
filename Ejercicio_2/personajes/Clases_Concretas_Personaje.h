#pragma once
#include "Mago.h"
class Hechicero : public Mago {
public:
    Hechicero() : Mago("Hechicero", 100, 100, 85, 70) {}
};

class Conjurador : public Mago {
public:
    Conjurador() : Mago("Conjurador", 100, 90, 75, 80) {}
};

class Brujo : public Mago {
public:
    Brujo() : Mago("Brujo", 100, 85, 90, 60) {}
};

class Nigromante : public Mago {
public:
    Nigromante() : Mago("Nigromante", 100, 110, 95, 65) {}
};



#include "Guerrero.h"

class Barbaro : public Guerrero {
public:
    Barbaro() : Guerrero("Bárbaro", 100, 40, 5, 20) {}
};

class Paladin : public Guerrero {
public:
    Paladin() : Guerrero("Paladín", 100, 30, 15, 15) {}
};

class Caballero : public Guerrero {
public:
    Caballero() : Guerrero("Caballero", 100, 25, 20, 18) {}
};


class Mercenario : public Guerrero {
public:
    Mercenario() : Guerrero("Mercenario", 100, 35, 10, 25) {}
};

class Gladiador : public Guerrero {
public:
    Gladiador() : Guerrero("Gladiador", 100, 28, 12, 22) {}
};