#include <iostream>
#include <cstdlib>

#include "Usuario.h"
#include "../utils/Console.h"
using namespace std;

Usuario::Usuario() {}

Usuario::Usuario(const std::string& nombre, 
				 const std::string& dni,
				 const std::string& correo,
				 const std::string&contrasena)
				 
{
	this->nombre=nombre;
	this->dni=dni;
	this->correo=correo;
	this->contrasena=contrasena;
}
void Usuario::verInformacion() const{
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"DNI: "<<dni<<endl;
	cout<<"Correo: "<<correo<<endl;
	cout<<"Contraseña: "<<contrasena<<endl; // Opcional: No se debe mostrar contraseña
	Console::reset();
	
	cout<<endl;
}

string Usuario::getNombre() const{
	return nombre;
}

bool Usuario::iniciarSesion(const std::string& userCorreo, const std::string& userContrasena){
	
	if (userCorreo==this->correo && userContrasena==this->contrasena){
		Console::printColor("✅ SESIÓN INICIADA CORRECTAMENTE. \n", 10);
		return true;
	}else{
		Console::printColor("❎ ERROR. CORREO O CONTRASEÑA INCORRECTO(S).\n", 12);
		return false;
	}
}