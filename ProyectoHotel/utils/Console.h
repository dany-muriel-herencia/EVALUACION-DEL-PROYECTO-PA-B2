#include <windows.h>
#include <string>

#ifndef CONSOLE_H
#define CONSOLE_H

class Console{
	private:
		static HANDLE hConsole;
	public:
		static void init();														// Inicializa las tildes y los colores
		static void setColor(int color);										// Elige un color para el texto
		static void reset();													// Resetea al color blanco. Es igual al color 15
		static void printColor(const std::string& text, int color);				// Escribe solo un texto de un color
		static void mostrarEncabezado(const std::string& titulo, int color=11);
		static std::string pedirString(const std::string& mensaje);
};
#endif