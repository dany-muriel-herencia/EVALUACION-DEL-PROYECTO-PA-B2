#include <iostream>

#include "Limpieza.h"
#include "../utils/Console.h"
using namespace std;

Limpieza::Limpieza(std::string _nombre, std::string _dni, std::string _correo,
				   std::string _contrasena, float _salario, std::string _fechaContratacion,
				   std::string _areaAsignada, int _nivelJerarquico)
		: Empleado(_nombre, _dni, _correo, _contrasena, "Personal de Limpieza", _salario, _fechaContratacion), areaAsignada(_areaAsignada), nivelJerarquico(_nivelJerarquico) {}

string Limpieza::getAreaAsignada() const{
	return areaAsignada;
}

int Limpieza::getNivelJerarquico() const{
	return nivelJerarquico;
}

void Limpieza::verInformacion() const{
	Empleado::verInformacion();
	
	Console::printColor("=== DATOS DE LIMPIEZA Y MANTENIMIENTO ===", 6);
	cout<<"\nÁrea Asignada: "<<areaAsignada<<endl;
	cout<<"Nivel Jerárquico: "<<nivelJerarquico<<endl;
}

void Limpieza::reportarDano(const std::string& ubicacion) const{
	Console::mostrarEncabezado("REPORTE DE DAÑOS", 6);
	Console::printColor("El personal de limpieza "+nombre+" ha reportado un daño en la ubicación: "+ubicacion+".\n", 15);
}