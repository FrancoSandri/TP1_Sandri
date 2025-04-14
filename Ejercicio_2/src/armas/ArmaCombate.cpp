#include "../headers/armas/ArmaCombate.h"
#include <iostream>

using namespace std;

ArmaCombate::ArmaCombate(string n, string t, string m, int f, int d, float w)
    : nombre(n), tipo(t), material(m), filo(f), durabilidad(d), peso(w) {}

string ArmaCombate::getNombre() const { return nombre; }
int ArmaCombate::getDanio() const { return filo; }
float ArmaCombate::getPeso() const { return peso; }
string ArmaCombate::getTipo() const { return tipo + " de " + material; }
void ArmaCombate::usar() { cout << nombre << " golpea con fuerza. Durabilidad restante: " << --durabilidad << "\n"; }
