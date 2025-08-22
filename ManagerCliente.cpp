#include <iostream>
#include <limits>
using namespace std;
#include "ManagerClientes.h"
#include "Clientes.h"
#include "ArchivoClientes.h"
void ManagerClientes::pausarYLimpiar()
{
    system("pause");
    system("cls");
}

void ManagerClientes::cargarCliente()
{
    Clientes reg;
    if(reg.cargarCliente())
    {
        if(_archiCliente.guardarCliente(reg))
        {
            cout<<"Carga exitosa!"<<endl;
        }
        else
        {
            cout<<"Error al cargar cliente"<<endl;
        }
    }

    else
    {
        cout<<"No fue posible cargar cliente"<<endl;
    }
    pausarYLimpiar();
}


Clientes* ManagerClientes::cargarTodosLosClientes(int& cantidad)
{
    cantidad = _archiCliente.getCantidadClientes();
    if(cantidad <= 0)
    {
        cout << "NO HAY CLIENTES" << endl;
        return nullptr;
    }

    Clientes* vec = new Clientes[cantidad];
    if(vec == nullptr)
    {
        cout << "No se pudo reservar memoria para clientes." << endl;
        return nullptr;
    }

    if(!_archiCliente.leerTodo(vec, cantidad))
    {
        cout << "NO SE PUDIERON LEER LOS CLIENTES" << endl;
        delete[] vec;
        return nullptr;
    }

    return vec;
    pausarYLimpiar();
}

void ManagerClientes::listarClientes()
{
    Clientes *vecCliente;
    int cantidad;

    vecCliente=cargarTodosLosClientes(cantidad);
    if(!vecCliente)
    {
        return;
    }
    for(int i=0; i<cantidad; i++)
    {
        vecCliente[i].mostrarCliente();
    }
    delete[] vecCliente;

}
void ManagerClientes::mostrarClientesActivos()
{
    int cantidad;
    Clientes *vecClientes;
    vecClientes=cargarTodosLosClientes(cantidad);
    if(!vecClientes)
    {
        return;
    }

    for(int i=0; i<cantidad; i++)
    {
        if(vecClientes[i].getEstado())
        {
            vecClientes[i].mostrarCliente();
        }
    }
    delete[] vecClientes;

}


void ManagerClientes::bajaCliente()
{
    mostrarClientesActivos();
    int dniCliente;
    Clientes reg;
    cout << "--- BAJA DE CLIENTE ---" << endl;

    cout << "Ingrese el DNI del cliente a dar de baja: ";
    dniCliente=validarEntero();
    int posicion=_archiCliente.getPosicion(dniCliente);
    if(posicion!=-1)
    {
        if(_archiCliente.bajaLogicaCliente(reg, posicion))
        {
            cout<<"El cliente fue dado de baja exitosamente"<<endl;
        }
        else
        {
            cout << "El cliente ya estaba dado de baja u ocurrió un error." << endl;
        }
    }
    else
    {
        cout<< "EL DNI NO EXISTE"<<endl;
    }
    pausarYLimpiar();
}
void ManagerClientes::altaCliente()
{
    listarClientes();
    int dniCliente;
    int posicion;

    cout << "--- ALTA DE CLIENTE ---" << endl;
    cout << "Ingrese el DNI del cliente a reactivar: ";
    dniCliente=validarEntero();

    posicion=_archiCliente.getPosicion(dniCliente);
    if(posicion !=-1)
    {
        Clientes reg;
        if(_archiCliente.altaLogicaCliente(reg, posicion))
        {
            cout<<"Cliente dado de alta exitosamente"<<endl;
        }
        else
        {
            cout<<"El cliente ya estaba activo"<<endl;
        }
    }
    else
    {
        cout<< "EL DNI NO EXISTE"<<endl;
    }
    pausarYLimpiar();
}

int ManagerClientes::validarEntero()
{
    int entero;
    while (true)
    {
        cin >> entero;

        if (cin.fail())
        {
            cout << "Entrada invalida. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            // Siempre limpiar el resto de la línea
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entero;
        }
    }
}

