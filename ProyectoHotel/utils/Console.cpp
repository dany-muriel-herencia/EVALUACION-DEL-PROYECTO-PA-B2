#include <iostream>
#include <cstdlib>

#include "Console.h"
using namespace std;

HANDLE Console::hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

void Console::init(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
}

void Console::setColor(int color){
	SetConsoleTextAttribute(hConsole, color);
}

void Console::reset(){
	SetConsoleTextAttribute(hConsole, 7);
}

void Console::printColor(const std::string& text, int color){
	SetConsoleTextAttribute(hConsole, color);
	cout<<text;
	SetConsoleTextAttribute(hConsole, 7);
}

void Console::mostrarEncabezado(const std::string& titulo, int color){
	setColor(color);
	cout<<"=================================\n";
	cout<<"   "<<titulo<<endl;
	cout<<"=================================\n";
	reset();	
}

string Console::pedirString(const std::string& mensaje){
	string input;
	cout<<mensaje;
	getline(cin, input);
	return input;
}