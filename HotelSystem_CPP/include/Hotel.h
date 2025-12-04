#ifndef HOTEL_H
#define HOTEL_H

#include <string>

class Cliente;
class Habitacion;

// Usuario (base)
class Usuario {
protected:
    std::string nombre;
    std::string dni;
    std::string correo;
public:
    Usuario() = default;
    Usuario(const std::string &n, const std::string &d, const std::string &c);
    virtual void verInformacion() const;
    virtual void iniciarSesion() const;
    virtual ~Usuario() = default;
};

// Empleado (base)
class Empleado {
protected:
    int idEmpleado;
    std::string nombre;
    float salario;
    std::string puesto;
public:
    Empleado() = default;
    Empleado(int id, const std::string &n, float s, const std::string &p);
    virtual void verDatos() const;
    virtual void realizarTarea() const;
    virtual ~Empleado() = default;
};

class Administrador : public Usuario {
public:
    void gestionarHabitaciones() const;
    void gestionarEmpleados() const;
    void gestionarStock() const;
};

class Recepcionista : public Empleado {
public:
    Recepcionista(int id, const std::string &n);
    void registrarCheckIn() const;
    void registrarCheckOut() const;
    void crearReservaPresencial() const;
    void consultarReserva() const;
    void mostrarDatosReserva() const;
};

class Limpieza : public Empleado {
public:
    Limpieza(int id, const std::string &n);
    void limpiarHabitacion() const;
    void marcarDisponibilidad() const;
};

class Cocinero : public Empleado {
public:
    Cocinero(int id, const std::string &n);
    void prepararComida() const;
};

class Mecanico : public Empleado {
public:
    Mecanico(int id, const std::string &n);
    void revisarInstalaciones() const;
    void realizarMantenimiento() const;
};

class Habitacion {
private:
    int numero{0};
    std::string tipo{"estandar"};
    std::string estado{"disponible"};
    float precio{0.0f};
    Cliente *ocupa{nullptr};
public:
    Habitacion() = default;
    Habitacion(int num, const std::string &t, float p);
    void asignarCliente(Cliente *c);
    void liberar();
    void verEstado() const;
};

class Reserva {
private:
    std::string codigoReserva;
    std::string fechaEntrada;
    std::string fechaSalida;
    Cliente *cliente{nullptr};
    Habitacion *habitacion{nullptr};
public:
    Reserva() = default;
    Reserva(const std::string &cod, const std::string &entrada, const std::string &salida);
    void setCliente(Cliente *c);
    void setHabitacion(Habitacion *h);
    void verDetalles() const;
    void cancelarReserva();
};

class Factura {
private:
    std::string codigoFactura;
    float montoTotal{0.0f};
public:
    Factura() = default;
    Factura(const std::string &cod, float monto);
    float calcularTotal() const;
    void imprimirFactura() const;
};

class Servicio {
private:
    std::string nombreServicio;
    float precio{0.0f};
public:
    Servicio() = default;
    Servicio(const std::string &n, float p);
    void verServicio() const;
};

class Stock {
private:
    std::string nombreItem;
    int cantidad{0};
    std::string tipo;
public:
    Stock() = default;
    Stock(const std::string &n, int c, const std::string &t);
    void agregarItem(int q = 1);
    void quitarItem(int q = 1);
    void verStock() const;
};

class Horario {
private:
    std::string horaEntrada;
    std::string horaSalida;
public:
    Horario() = default;
    Horario(const std::string &in, const std::string &out);
    void verHorario() const;
};

// Cliente (definicion)
class Cliente : public Usuario {
public:
    Cliente() = default;
    Cliente(const std::string &n);
    void hacerReserva() const;
    void solicitarServicio() const;
    void verFactura() const;
};

#endif // HOTEL_H
