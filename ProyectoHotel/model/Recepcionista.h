#include <string>

#include "Empleado.h"

#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H

class Recepcionista:public Empleado{
	private:
		std::string turno;
		int extensionTelefonica;
	public:
		Recepcionista(std::string _nombre, std::string _dni, std::string _correo,
					  std::string _contrasena, float _salario, std::string _fechaContratacion,
					  std::string _turno, int _extensionTelefonica);
		std::string getTurno() const;
		int getExtensionTelefonica() const;
		
		void verInformacion() const override;
		
		void registrarHuesped() const;
		
		virtual ~Recepcionista()=default;
};
#endif