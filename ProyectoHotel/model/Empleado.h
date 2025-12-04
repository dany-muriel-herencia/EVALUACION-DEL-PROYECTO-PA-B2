#include <string>

#include "Usuario.h"

#ifndef EMPLEADO_H
#define EMPLEADO_H

class Empleado:public Usuario{
	protected:
		std::string cargo;
		double salario;
		std::string fechaContratacion;
	public:
		Empleado(std::string _nombre, std::string _dni, std::string _correo,
				 std::string _contrasena, std::string _caargo, float _salario,
				 std::string _fechaContratacion);
		std::string getCargo() const;
		float getSalario() const;
		std::string getFechaContratacion() const;
		
		void verInformacion() const override;
		
		virtual ~Empleado()=default;
};
#endif