#include <iostream>
#include <string>
#include <vector>
#include "../include/Hotel.h"

int main() {
    // Demo rapido
    Cliente cliente("Juan Perez");
    cliente.verInformacion();

    Recepcionista recep(1, "Ana");
    recep.verDatos();
    recep.crearReservaPresencial();

    Habitacion h101(101, "Doble", 75.0f);
    h101.verEstado();

    Reserva r("R-1001", "2025-12-01", "2025-12-05");
    r.setCliente(&cliente);
    r.setHabitacion(&h101);
    r.verDetalles();

    Factura f("F-9001", 300.50f);
    f.imprimirFactura();

    Stock s("Toallas", 20, "Limpieza");
    s.verStock();
    s.quitarItem(2);

    Horario horario("08:00", "17:00");
    horario.verHorario();

    return 0;
}
