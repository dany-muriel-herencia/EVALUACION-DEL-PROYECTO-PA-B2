#include <string>

#include "Empleado.h"

#ifndef LIMPIEZA_H
#define LIMPIEZA_H

class Limpieza:public Empleado{
	private:
		std::string areaAsignada;
		int nivelJerarquico;
	public:
		Limpieza(std::string _nombre, std::string _dni, std::string _correo,
				 std::string _contrasena, float _salario, std::string _fechaContratacion,
				 std::string _areaAsignada, int _niveljerarquico);
		std::string getAreaAsignada() const;
		int getNivelJerarquico() const;
		
		void verInformacion() const override;
		
		void reportarDano(const std::string& ubicado) const;
		
		virtual ~Limpieza()=default;
};
#endif