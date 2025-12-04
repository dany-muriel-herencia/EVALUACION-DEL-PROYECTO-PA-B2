#include <iostream>

#include "../utils/Console.h"
#include "Empleado.h"
using namespace std;

Empleado::Empleado(std::string _nombre, std::string _dni, std::string _correo,
				   std::string _contrasena, std::string _cargo, float _salario,
				   std::string _fechaContratacion)
		: Usuario (_nombre, _dni, _correo, _contrasena),cargo(_cargo), salario(_salario), fechaContratacion(_fechaContratacion) {}

string Empleado::getCargo() const{
	return cargo;
}

float Empleado::getSalario() const{
	return salario;
}

string Empleado::getFechaContratacion() const{
	return fechaContratacion;
}

void Empleado::verInformacion() const{
	Usuario::verInformacion();
	Console::printColor("=== INFORMACIÓN DEL EMPLEADO ===", 6);
	cout<<"Cargo: "<<cargo<<endl;
	cout<<"Salario: S/."<<salario<<endl;
	cout<<"Fecha de Contratación: "<<fechaContratacion<<endl;
}