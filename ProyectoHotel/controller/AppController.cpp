#include <iostream>
#include <limits>		// std::numeric_limits
#include <cstdlib>		// system("____")

#include "AppController.h"
#include "../utils/Console.h"
#include "../model/Model.h"
using namespace std;

vector<Usuario*> AppController::cuentasCreadas;

void AppController::iniciarApp(){
	int opcion;
	do{
		mostrarMenuPrincipal();
		opcion=pedirOpcion();
		manejarOpcion(opcion);
		
		if (opcion!=4){
			cout<<"Presione una tecla para continuar...";
			system("pause>null");
			system("cls");
		}
	}while(opcion!=4);
	
	for (Usuario* u:cuentasCreadas){
		delete u;
	}
	cuentasCreadas.clear();
}

int AppController::pedirOpcion(){
	int opcion;
	cout<<"Ingrese su opción: ";
	while (!(cin>>opcion)){
		Console::printColor("Entrada inválida. Ingrese un número.\n", 12);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Ingrese su opción: ";
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	return opcion;
}
	
void AppController::mostrarMenuPrincipal(){
		Console::mostrarEncabezado("SISTEMA DE GESTIÓN HOTELERA", 6);
		cout<<"1) Iniciar Sesión\n2) Crear Cuenta\n3) Ver Cuentas Existentes\n4) Salir del Programa\n";
}
	
void AppController::procesoInicioSesion(){
	
		Console::mostrarEncabezado("INICIO DE SESIÓN", 6);
		string inputCorreo=Console::pedirString(" Correo: ");
		string inputContrasena=Console::pedirString(" Contraseña: ");
		
		Usuario* usuarioEncontrado=nullptr;
		
		for (Usuario* u:cuentasCreadas){
			if (u->iniciarSesion(inputCorreo, inputContrasena)){
				usuarioEncontrado=u;
				break;
			}
		}
		
		if (usuarioEncontrado!=nullptr){
			string mensajeBienvenida="¡Bienvenido, "+usuarioEncontrado->getNombre()+"!\n";
			Console::printColor(mensajeBienvenida, 10);
		}else{
			Console::printColor("No se pudo iniciar sesión. Verifique sus credenciales.\n", 12);
		}
}

void AppController::procesoCrearCuenta(){
	Console::mostrarEncabezado("CREAR NUEVA CUENTA", 6);
	string nombre=Console::pedirString(" Nombre completo: ");
	string dni=Console::pedirString(" DNI: ");
	string correo=Console::pedirString(" Correo electrónico: ");
	string contrasena=Console::pedirString(" Contrasena: ");
	
	Usuario* nuevoUsuario=new Usuario(nombre, dni, correo, contrasena);
	
	AppController::cuentasCreadas.push_back(nuevoUsuario);
	
	Console::printColor("✅ Cuenta creada exitosamente\n", 10);
}

void AppController::manejarOpcion(int opcion){
	switch (opcion){
		case 1:
			procesoInicioSesion();
			break;
		case 2:
			procesoCrearCuenta();
			break;
		case 3:
			procesoVerCuentas();
			break;	
		case 4:
			Console::printColor("¡Gracias por usar el sistema! Saliendo...\n", 3);
			break;
		default:
			Console::printColor("Opción no válida. Intente de nuevo.\n", 12);
			break;
	}
}

void AppController::procesoVerCuentas(){
	Console::mostrarEncabezado("CUENTAS DE USUARIOS REGISTRADAS", 6);
	if (cuentasCreadas.empty()){
		Console::printColor("Actualmente no hay cuentas registradas.\n", 12);
		return;
	}
	
	for (size_t i=0; i<cuentasCreadas.size(); ++i){
		string encabezado="- USUARIO "+to_string(i+1)+" -";
		Console::printColor(encabezado, 3);
		cout<<endl;
		cuentasCreadas[i]->verInformacion();
	}
}