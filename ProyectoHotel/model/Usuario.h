#include <string>

#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
	protected:
		std::string nombre;
		std::string dni;
		std::string correo;
		std::string contrasena;
	public:
		Usuario();								// Constructor por defecto
		Usuario(const std::string& nombre,		// Constructor con datos
				const std::string& dni,
				const std::string& correo,
				const std::string& contrasena);
		virtual void verInformacion() const;
		virtual bool iniciarSesion(const std::string& userCorreo, const std::string& userContrasena);
		std::string getNombre() const;
	virtual ~Usuario()=default;
};
#endif