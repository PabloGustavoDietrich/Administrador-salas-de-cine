#ifndef MANAGERCLIENTES_H_INCLUDED
#define MANAGERCLIENTES_H_INCLUDED
#include "Clientes.h"
#include "ArchivoClientes.h"
#include <string>

class ManagerClientes{
public:
    void pausarYLimpiar();
    void cargarCliente();
    Clientes* cargarTodosLosClientes(int& cantidad);
    void mostrarClientesActivos();
    void altaCliente();
    void bajaCliente();
    void modificarCliente();
    void listarClientes();
    int validarEntero();

private:
 ArchivoClientes _archiCliente;
};


#endif // MANAGERCLIENTES_H_INCLUDED
