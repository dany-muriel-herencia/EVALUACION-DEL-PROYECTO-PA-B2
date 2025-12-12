#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"

class Administrador : public Usuario {
public:
    Administrador(string n, string d, string c, string p);

    void gestionarHabitaciones();
    void gestionarEmpleados();
    void gestionarStock();
};

#endif
