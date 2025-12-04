#include <string>
#include "Usuario.h"

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador:public Usuario{
	private:
		std::string departamento;
		int nivelAcceso;
	public:
		Administrador(std::string& _nombre, std::string& _dni, std::string& _correo,
					  std::string& _contrasena, std::string _departmento, int _nivelAcceso);
		
		std::string getDepartamento() const;
		int getNivelAcceso() const;
		
		void verInformacion() const override;
		
		void gestionarEmpleados() const;
		
		void generarReporteFinanciero() const;
		
		virtual ~Administrador()=default;
};
#endif