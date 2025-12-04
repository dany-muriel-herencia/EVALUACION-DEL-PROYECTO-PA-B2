#include "../include/Hotel.h"
#include <iostream>

// Implementaciones sencillas para demo
Usuario::Usuario(const std::string &n, const std::string &d, const std::string &c)
    : nombre(n), dni(d), correo(c) {}

void Usuario::verInformacion() const {
    std::cout << "Usuario: " << nombre << " | DNI: " << dni << " | Correo: " << correo << '\n';
}

void Usuario::iniciarSesion() const {
    std::cout << nombre << " inicia sesion (placeholder)\n";
}

Empleado::Empleado(int id, const std::string &n, float s, const std::string &p)
    : idEmpleado(id), nombre(n), salario(s), puesto(p) {}

void Empleado::verDatos() const {
    std::cout << "Empleado " << idEmpleado << ": " << nombre << " | Puesto: " << puesto << " | Salario: " << salario << '\n';
}

void Empleado::realizarTarea() const { std::cout << nombre << " realiza una tarea generica\n"; }

void Administrador::gestionarHabitaciones() const { std::cout << "Administrador gestiona habitaciones\n"; }
void Administrador::gestionarEmpleados() const { std::cout << "Administrador gestiona empleados\n"; }
void Administrador::gestionarStock() const { std::cout << "Administrador gestiona stock\n"; }

Recepcionista::Recepcionista(int id, const std::string &n) : Empleado(id, n, 0.0f, "Recepcionista") {}
void Recepcionista::registrarCheckIn() const { std::cout << nombre << " registra Check-In\n"; }
void Recepcionista::registrarCheckOut() const { std::cout << nombre << " registra Check-Out\n"; }
void Recepcionista::crearReservaPresencial() const { std::cout << nombre << " crea reserva presencial\n"; }
void Recepcionista::consultarReserva() const { std::cout << nombre << " consulta reserva\n"; }
void Recepcionista::mostrarDatosReserva() const { std::cout << nombre << " muestra datos de reserva\n"; }

Limpieza::Limpieza(int id, const std::string &n) : Empleado(id, n, 0.0f, "Limpieza") {}
void Limpieza::limpiarHabitacion() const { std::cout << nombre << " limpia habitacion\n"; }
void Limpieza::marcarDisponibilidad() const { std::cout << nombre << " marca disponibilidad\n"; }

Cocinero::Cocinero(int id, const std::string &n) : Empleado(id, n, 0.0f, "Cocinero") {}
void Cocinero::prepararComida() const { std::cout << nombre << " prepara comida\n"; }

Mecanico::Mecanico(int id, const std::string &n) : Empleado(id, n, 0.0f, "Mecanico") {}
void Mecanico::revisarInstalaciones() const { std::cout << nombre << " revisa instalaciones\n"; }
void Mecanico::realizarMantenimiento() const { std::cout << nombre << " realiza mantenimiento\n"; }

Habitacion::Habitacion(int num, const std::string &t, float p) : numero(num), tipo(t), precio(p) {}
void Habitacion::asignarCliente(Cliente *c) { ocupa = c; estado = "ocupado"; std::cout << "Habitacion "<< numero << " asignada a cliente\n"; }
void Habitacion::liberar() { ocupa = nullptr; estado = "disponible"; }
void Habitacion::verEstado() const { std::cout << "Habitacion "<< numero << " - " << tipo << " - " << estado << " - $" << precio << '\n'; }

Reserva::Reserva(const std::string &cod, const std::string &entrada, const std::string &salida) : codigoReserva(cod), fechaEntrada(entrada), fechaSalida(salida) {}
void Reserva::setCliente(Cliente *c) { cliente = c; }
void Reserva::setHabitacion(Habitacion *h) { habitacion = h; }
void Reserva::verDetalles() const { std::cout << "Reserva "<< codigoReserva << " desde " << fechaEntrada << " hasta " << fechaSalida << '\n'; }
void Reserva::cancelarReserva() { std::cout << "Reserva "<< codigoReserva << " cancelada\n"; }

Factura::Factura(const std::string &cod, float monto) : codigoFactura(cod), montoTotal(monto) {}
float Factura::calcularTotal() const { return montoTotal; }
void Factura::imprimirFactura() const { std::cout << "Factura " << codigoFactura << " - Total: $" << montoTotal << '\n'; }

Servicio::Servicio(const std::string &n, float p) : nombreServicio(n), precio(p) {}
void Servicio::verServicio() const { std::cout << "Servicio: "<< nombreServicio << " - $" << precio << '\n'; }

Stock::Stock(const std::string &n, int c, const std::string &t) : nombreItem(n), cantidad(c), tipo(t) {}
void Stock::agregarItem(int q) { cantidad += q; std::cout << "Agregado "<< q << " de "<< nombreItem <<". Total: "<< cantidad <<"\n"; }
void Stock::quitarItem(int q) { cantidad = (cantidad - q >= 0) ? cantidad - q : 0; std::cout << "Quitado "<< q <<" de "<< nombreItem <<". Total: "<< cantidad <<"\n"; }
void Stock::verStock() const { std::cout << nombreItem << " ("<< tipo <<") : "<< cantidad <<"\n"; }

Horario::Horario(const std::string &in, const std::string &out) : horaEntrada(in), horaSalida(out) {}
void Horario::verHorario() const { std::cout << "Horario: "<< horaEntrada << " - " << horaSalida << '\n'; }

Cliente::Cliente(const std::string &n) { nombre = n; }
void Cliente::hacerReserva() const { std::cout << nombre << " hace una reserva\n"; }
void Cliente::solicitarServicio() const { std::cout << nombre << " solicita un servicio\n"; }
void Cliente::verFactura() const { std::cout << nombre << " revisa su factura\n"; }
