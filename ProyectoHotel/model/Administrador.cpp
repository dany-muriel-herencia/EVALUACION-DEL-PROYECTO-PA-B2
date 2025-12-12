#include "Administrador.h"
#include <iostream>

Administrador::Administrador(string n, string d, string c, string p) 
    : Usuario(n, d, c, p) {}

void Administrador::gestionarHabitaciones() {
    cout << "Entrando a modulo de gestion de habitaciones..." << endl;
}

void Administrador::gestionarEmpleados() {
    cout << "Entrando a modulo de gestion de empleados..." << endl;
}

void Administrador::gestionarStock() {
    cout << "Entrando a modulo de stock..." << endl;
}
