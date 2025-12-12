#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> 
#include <fstream>
#include <sstream>

#include "model/Usuario.h"
#include "model/Cliente.h"
#include "model/Empleado.h"
#include "model/Administrador.h"
#include "model/Recepcionista.h"
#include "model/Limpieza.h"
#include "model/Cocinero.h"
#include "model/Mecanico.h"
#include "model/Habitacion.h"
#include "model/Reserva.h"
#include "model/Stock.h"
#include "model/Servicio.h"
#include "model/Factura.h"
#include "model/Boleta.h" 

using namespace std;

vector<Habitacion*> habitaciones;
vector<Empleado*> empleados;
vector<Cliente*> clientes;
vector<Stock*> inventario;
vector<Reserva*> reservas;

void guardarDatos() {
    ofstream fh("datos/habitaciones.txt");
    if(fh.is_open()) {
        for(auto h : habitaciones) {
            fh << h->getNumero() << "|" << h->getTipo() << "|" << h->getPrecio() << "|" << h->getEstado() << "\n";
        }
        fh.close();
    }

    ofstream fs("datos/stock.txt");
    if(fs.is_open()) {
        for(auto s : inventario) {
            fs << s->getNombre() << "|" << s->getCantidad() << "|" << s->getTipo() << "|" << s->getPrecio() << "\n";
        }
        fs.close();
    }
    
    ofstream fc("datos/clientes.txt");
    if(fc.is_open()) {
        for(auto c : clientes) {
            fc << c->getNombre() << "|" << c->getDni() << "\n";
        }
        fc.close();
    }
    
    ofstream fr("datos/reservas.txt");
    if(fr.is_open()) {
        for(auto r : reservas) {
             fr << r->getCodigo() << "\n"; 
        }
        fr.close();
    }
    
    ofstream fe("datos/empleados.txt");
    if(fe.is_open()) {
        for(auto e : empleados) {
            fe << e->getNombre() << "|" << e->getDni() << "\n";
        }
        fe.close();
    }
}

void cargarDatos() {
    ifstream fh("datos/habitaciones.txt");
    if(fh.is_open()) {
        string linea;
        habitaciones.clear(); 
        while(getline(fh, linea)) {
            stringstream ss(linea);
            string numeroStr, tipo, precioStr, estado;
            getline(ss, numeroStr, '|');
            getline(ss, tipo, '|');
            getline(ss, precioStr, '|');
            getline(ss, estado, '|');
            
            if(!numeroStr.empty()) {
                Habitacion* h = new Habitacion(stoi(numeroStr), tipo, stof(precioStr));
                h->setEstado(estado);
                habitaciones.push_back(h);
            }
        }
        fh.close();
    } else {
        habitaciones.push_back(new Habitacion(101, "Simple", 50.0));
        habitaciones.push_back(new Habitacion(102, "Doble", 80.0));
        habitaciones.push_back(new Habitacion(201, "Suite", 150.0));
        habitaciones.push_back(new Habitacion(202, "Matrimonial", 100.0));
    }

    ifstream fs("datos/stock.txt");
    if(fs.is_open()) {
        string linea;
        inventario.clear(); 
        while(getline(fs, linea)) {
             stringstream ss(linea);
             string nombre, cantStr, tipo, precioStr;
             getline(ss, nombre, '|');
             getline(ss, cantStr, '|');
             getline(ss, tipo, '|');
             getline(ss, precioStr, '|');
             
             float precio = 0.0;
             if(!precioStr.empty()) precio = stof(precioStr);
             
             if(!nombre.empty()) {
                 inventario.push_back(new Stock(nombre, stoi(cantStr), tipo, precio));
             }
        }
        fs.close();
    } else {
        if(inventario.empty()) {
            inventario.push_back(new Stock("Jabones", 100, "Limpieza", 2.50));
            inventario.push_back(new Stock("Toallas", 50, "Limpieza", 10.0));
            inventario.push_back(new Stock("Agua Mineral", 200, "Bebida", 2.0));
            inventario.push_back(new Stock("Sandwich", 50, "Comida", 5.0));
            inventario.push_back(new Stock("Gaseosa", 100, "Bebida", 3.0));
        }
    }

    ifstream fc("datos/clientes.txt");
    if(fc.is_open()) {
        string linea;
        clientes.clear();
        while(getline(fc, linea)) {
            stringstream ss(linea);
            string nombre, dni;
            getline(ss, nombre, '|');
            getline(ss, dni, '|');
            if(!nombre.empty()) {
                clientes.push_back(new Cliente(nombre, dni, "email@dummy.com", "123"));
            }
        }
        fc.close();
    }
}

void inicializarDatos() {
    cargarDatos(); 

    if (empleados.empty()) {
        empleados.push_back(new Recepcionista("Ana Lopez", "1111", "ana@hotel.com", "123", 1, 1200));
        empleados.push_back(new Limpieza("Carlos Ruiz", "2222", "carlos@hotel.com", "123", 2, 900));
        empleados.push_back(new Cocinero("Luis Chef", "3333", "luis@hotel.com", "123", 3, 1500));
        empleados.push_back(new Mecanico("Pedro Fix", "4444", "pedro@hotel.com", "123", 4, 1100));
    }
}

void pause() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostrarMenuPrincipal() {
    limpiarPantalla();
    cout << "======================================\n";
    cout << "      SISTEMA DE GESTION HOTELERA     \n";
    cout << "======================================\n";
    cout << "1. Acceso Administrador\n";
    cout << "2. Acceso Empleado\n";
    cout << "3. Acceso Cliente\n";
    cout << "4. Salir\n";
    cout << "======================================\n";
    cout << "Seleccione una opcion: ";
}

void adminEliminarEmpleado() {
    string dni;
    cout << "Ingrese DNI del empleado a eliminar: ";
    cin >> dni;
    
    auto it = remove_if(empleados.begin(), empleados.end(), 
        [&dni](Empleado* e){ return e->getDni() == dni; });
        
    if(it != empleados.end()) {
        empleados.erase(it, empleados.end());
        cout << "Empleado eliminado correctamente.\n";
        guardarDatos();
    } else {
        cout << "Empleado no encontrado.\n";
    }
}

void adminLiberarHabitacion() {
    int num;
    cout << "Ingrese numero de habitacion a liberar forzosamente: ";
    cin >> num;
    
    bool found = false;
    for(auto h : habitaciones) {
        if(h->getNumero() == num) {
            h->setEstado("Disponible");
            h->liberar(); 
            cout << "Habitacion " << num << " ahora esta disponible.\n";
            found = true;
            break;
        }
    }
    if(found) guardarDatos();
    else cout << "Habitacion no encontrada.\n";
}

void adminAgregarStock() {
    string nom, tipo;
    int cant;
    float precio;
    
    cout << "Nombre del producto: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Cantidad inicial: ";
    cin >> cant;
    cout << "Tipo (Comida/Bebida/Limpieza): ";
    cin >> tipo;
    cout << "Precio unitario: ";
    cin >> precio;
    
    inventario.push_back(new Stock(nom, cant, tipo, precio));
    cout << "Producto agregado al inventario.\n";
    guardarDatos();
}

void menuAdministrador() {
    Administrador admin("Admin Principal", "9999", "admin@hotel.com", "admin");
    string pass;
    cout << "Ingrese password de administrador: ";
    cin >> pass;
    if (pass != "admin") {
        cout << "Acceso denegado.\n";
        pause();
        return;
    }

    int opt;
    do {
        limpiarPantalla();
        cout << "--- PANEL ADMINISTRADOR ---\n";
        cout << "1. Gestionar Habitaciones\n";
        cout << "2. Gestionar Empleados\n";
        cout << "3. Gestionar Stock\n";
        cout << "4. Eliminar Empleado\n";
        cout << "5. Desocupar Habitacion\n";
        cout << "6. Agregar Stock\n";
        cout << "7. Volver\n";
        cout << "Opcion: ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "\nLista de Habitaciones:\n";
                for(auto h : habitaciones) h->verEstado();
                pause();
                break;
            case 2:
                cout << "\nLista de Empleados:\n";
                for(auto e : empleados) e->verDatos();
                pause();
                break;
            case 3:
                cout << "\nInventario:\n";
                for(auto s : inventario) s->verStock();
                pause();
                break;
            case 4: adminEliminarEmpleado(); pause(); break;
            case 5: adminLiberarHabitacion(); pause(); break;
            case 6: adminAgregarStock(); pause(); break;
        }
    } while (opt != 7);
}

void clientePedirComidaBebida(Cliente* cliente) {
    cout << "\n--- MENU RESTAURANTE Y BAR ---\n";
    cout << "Productos disponibles:\n";
    
    vector<Stock*> disponibles;
    int index = 1;
    for(auto s : inventario) {
        if((s->getTipo() == "Comida" || s->getTipo() == "Bebida") && s->getCantidad() > 0) {
            cout << index << ". " << s->getNombre() << " - $" << s->getPrecio() << " (" << s->getCantidad() << " disp.)\n";
            disponibles.push_back(s);
            index++;
        }
    }
    
    if(disponibles.empty()) {
        cout << "No hay productos disponibles por el momento.\n";
        return;
    }
    
    int sel;
    cout << "Seleccione producto (0 para cancelar): ";
    cin >> sel;
    
    if(sel > 0 && sel <= disponibles.size()) {
        Stock* itemSeleccionado = disponibles[sel-1];
        int cant;
        cout << "Cantidad: ";
        cin >> cant;
        
        if(itemSeleccionado->verificarDisponibilidad(cant)) {
            itemSeleccionado->descontar(cant);
            float total = itemSeleccionado->getPrecio() * cant;
            
            cout << "Generando cobro por $" << total << "...\n";
            Boleta bol("BOL-REST-" + to_string(rand()%999), "HOY", cliente->getNombre(), cliente->getDni());
            
            Item* it = new Item(itemSeleccionado->getNombre(), cant, itemSeleccionado->getPrecio());
            bol.agregarItem(it);
            bol.imprimir();
            
            guardarDatos(); 
            cout << "Pedido entregado. Buen provecho!\n";
        } else {
            cout << "Stock insuficiente.\n";
        }
    }
}

void menuCliente() {
    string nombre, dni;
    cout << "--- ACCESO CLIENTE ---\n";
    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese su DNI: ";
    cin >> dni;

    Cliente* clienteActual = nullptr;
    for(auto c : clientes) {
        if(c->getDni() == dni) {
            clienteActual = c;
            break;
        }
    }
    
    if(!clienteActual) {
        clienteActual = new Cliente(nombre, dni, "email@dummy.com", "123");
        clientes.push_back(clienteActual);
        guardarDatos();
        cout << "Bienvenido nuevo cliente!\n";
    }

    int opt;
    do {
        limpiarPantalla();
        cout << "Bienvenido, " << clienteActual->getNombre() << "\n";
        cout << "1. Hacer Reserva\n";
        cout << "2. Pedir Comida/Bebidas\n";
        cout << "3. Ver Documentos\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opt;

        if (opt == 1) {
            cout << "--- RESERVAS ---\n";
             for(auto h : habitaciones) {
                if(h->getEstado() == "Disponible") h->verEstado();
            }
            int num;
            cout << "Habitacion #: "; cin >> num;
            
            bool ok = false;
            for(auto h: habitaciones) { 
                if(h->getNumero() == num && h->getEstado()=="Disponible"){ 
                    h->setEstado("Ocupada"); h->asignarCliente(clienteActual);
                    reservas.push_back(new Reserva("RES"+to_string(num), "HOY", "MANANA", clienteActual, h));
                    ok=true; 
                    cout << "Reservado!\n"; 
                    guardarDatos(); 
                    break;
                }
            }
            if(!ok) cout << "No disponible o invalido.\n";
            pause();
        } else if (opt == 2) {
            clientePedirComidaBebida(clienteActual);
            pause();
        } else if (opt == 3) {
            clienteActual->verFactura(); 
            pause();
        }

    } while (opt != 4);
}

void menuEmpleado() {
    string dni;
    cout << "Ingrese su DNI de empleado: ";
    cin >> dni;
    Empleado* u = nullptr;
    for(auto e : empleados) if(e->getDni() == dni) u = e;
    
    if(!u) { cout << "No encontrado\n"; pause(); return; }
    
    limpiarPantalla();
    u->realizarTarea();
    
    Recepcionista* r = dynamic_cast<Recepcionista*>(u);
    Limpieza* l = dynamic_cast<Limpieza*>(u);
    Cocinero* c = dynamic_cast<Cocinero*>(u);
    Mecanico* m = dynamic_cast<Mecanico*>(u);

    if(r) {
        int op; cout << "1. Registrar CheckIn\n2. Registrar CheckOut\n3. Salir\nOp: "; cin >> op;
        if(op==1) {
            r->registrarCheckIn(habitaciones);
            guardarDatos();
        } 
        if(op==2) {
            r->registrarCheckOut(habitaciones);
            guardarDatos();
        }
    }
    else if(l) {
        int op; cout << "1. Limpiar Hab\n2. Marcar Disp.\n3. Salir\nOp: "; cin >> op;
        if(op==1) { int n; cout<<"Hab #:"; cin>>n; l->limpiarHabitacion(n); }
        if(op==2) { int n; cout<<"Hab #:"; cin>>n; l->marcarDisponibilidad(n); 
                    for(auto h:habitaciones) if(h->getNumero()==n) h->setEstado("Disponible"); guardarDatos(); }
    }
    else if(c) {
        int op; cout << "1. Preparar Pedido\n2. Verificar Stock\n3. Salir\nOp: "; cin>>op;
        if(op==1) {
             string plato; cout<<"Plato: "; cin.ignore(); getline(cin, plato);
             c->prepararPedido(plato);
        }
        if(op==2) {
            string ing; int cant;
            cout<<"Ingrediente: "; cin>>ing; cout<<"Cant: "; cin>>cant;
            if(c->verificarStock(ing, cant)) cout<<"Stock SI disponible.\n"; else cout<<"Stock NO disponible.\n";
        }
    }
    else if(m) {
        int op; cout << "1. Revisar Instalaciones\n2. Mantenimiento\n3. Salir\nOp: "; cin>>op;
        if(op==1) m->revisarInstalaciones(habitaciones);
        if(op==2) {
            m->realizarMantenimiento(habitaciones);
            guardarDatos();
        }
    }
    
    pause();
}

int main() {
    inicializarDatos();
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        switch (opcion) {
            case 1: menuAdministrador(); break;
            case 2: menuEmpleado(); break;
            case 3: menuCliente(); break;
        }
    } while (opcion != 4);
    
    cout << "Guardando datos y saliendo...\n";
    guardarDatos();
    return 0;
}
