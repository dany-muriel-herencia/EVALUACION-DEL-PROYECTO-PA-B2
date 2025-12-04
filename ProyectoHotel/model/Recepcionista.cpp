#include <iostream>

#include "Recepcionista.h"
#include "../utils/Console.h"
using namespace std;

Recepcionista::Recepcionista(std::string _nombre, std::string _dni, std::string _correo,
							 std::string _contrasena, float _salario, std::string _fechaContratacion,
							 std::string _turno, int _extensionTelefonica)
			 : Empleado(_nombre, _dni, _correo, _contrasena, "Recepcionista", _salario, fechaContratacion), turno(_turno), extensionTelefonica(_extensionTelefonica) {}

string Recepcionista::getTurno() const{
	return turno;
}

int Recepcionista::getExtensionTelefonica() const{
	return extensionTelefonica;
}

void Recepcionista::verInformacion() const{
	Empleado::verInformacion();
	Console::printColor("=== DATOS DE RECEPCIÓN ===", 6);
	cout<<"\nTurno Asignado: "<<turno<<endl;
	cout<<"Extension Telefónica: "<<extensionTelefonica<<endl;
}

void Recepcionista::registrarHuesped() const{
	Console::mostrarEncabezado("REGISTRO DE HUÉSPED", 3);
	Console::printColor("La recepcionista "+nombre+"está registrando la entrada de un nuevo huésped.\n", 15);
}