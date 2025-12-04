#include <iostream>
#include <cstdlib>

#include "model/Usuario.h"
#include "model/Administrador.h"
#include "utils/Console.h"
#include "controller/AppController.h"
using namespace std;


int main(){
	Console::init();																	// Tildes, eñes y colores
	/*
	Console::mostrarEncabezado("PRESENTACIÓN", 6);
	Console::reset();
	cout<<"1. Dany Muriel\n2. Annet ___\n3. Jair Mendoza\n";
	system("pause");
	system("cls");
	*/
	AppController::iniciarApp();
	
	return 0;
}