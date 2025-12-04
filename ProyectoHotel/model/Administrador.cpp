#include <iostream>

#include "Administrador.h"
#include "../utils/Console.h"
using namespace std;

Administrador::Administrador(std::string& _nombre, std::string& _dni, std::string& _correo,
							 std::string& _contrasena, std::string _departamento, int _nivelAcceso)
			 : Usuario(_nombre, _dni, _correo, _contrasena), departamento(_departamento), nivelAcceso(_nivelAcceso) {}

string Administrador::getDepartamento() const{
	return departamento;
}

int Administrador::getNivelAcceso() const{
	return nivelAcceso;
}

void Administrador::verInformacion() const{
	Usuario::verInformacion();
	
	Console::printColor("=== DATOS DE ADMINISTRACIÓN ===", 6);
	cout<<"\nDepartamento: "<<departamento<<endl;
	cout<<"Nivel de Acceso: "<<nivelAcceso<<endl;
}

void Administrador::gestionarEmpleados() const{
	Console::mostrarEncabezado("GESTIÓN DE EMPLEADOS", 6);
	Console::printColor("El administrador "+nombre+" está ingresando al módulo de gestión de personal.\n", 15);
}

void Administrador::generarReporteFinanciero() const{
	Console::mostrarEncabezado("REPORTE FINANCIERO", 6);
	Console::printColor("El administrador "+nombre+" está generando reportes del estado financiero del hotel.\n", 15);
}