#include <string>
#include <vector>

#include "../model/Model.h"
#include "../utils/Console.h"

#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

class AppController{
	public:
		static void iniciarApp();
	private:
		static std::vector<Usuario*> cuentasCreadas;
		static void mostrarMenuPrincipal();
		static int pedirOpcion();
		static void manejarOpcion(int opcion);
		static void procesoInicioSesion();
		static void procesoCrearCuenta();
		static void procesoVerCuentas();
};
#endif
