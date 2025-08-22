#include <iostream>
using namespace std;
#include "Fecha.h"
#include "Constante.h"
#include "ManagerEntrada.h"

void ManagerEntrada::cargarEntrada()
{
    Entrada* vecEntradas = nullptr;
    int cantidadCompradas = 0;
    Entrada registro;

    if (registro.cargarEntradas(vecEntradas, cantidadCompradas))
    {
        cout<< "ENTRADAS CARGADAS CON EXITO"<<endl;

        if(_archiTikets.guardarEntradasCompradas(vecEntradas, cantidadCompradas)){
            cout<< "ENTRADAS GUARDADAS CON EXITO"<<endl;
        }else{
            cout<< "NO SE PUDIERON GUARDAR LAS ENTRADAS"<<endl;
        }
    }
    else
    {
        cout << "Error al cargar las entradas." << endl;
    }
    delete[] vecEntradas;
    system("pause");
    system("cls");
}

Entrada* ManagerEntrada::cargarTodasLasEntradas(int& cantidad)
{
    cantidad = _archiTikets.getCantidadDeEntradas();
    if(cantidad <= 0)
    {
        cout << "NO HAY ENTRADAS PARA MOSTRAR" << endl;
        return nullptr;
    }

    Entrada* vec = new Entrada[cantidad];
    if(vec == nullptr)
    {
        cout << "NO SE PUDO RESERVAR MEMORIA PARA LAS ENTRADAS." << endl;
        return nullptr;
    }

    if(!_archiTikets.leerTodas(vec, cantidad))
    {
        cout << "NO SE PUDIERON LEER LAS ENTRADAS" << endl;
        delete[] vec;
        return nullptr;
    }
    return vec;
}

void ManagerEntrada::mostrarEntradas()
{
    int cantidad;
    Entrada* vecEntradas= cargarTodasLasEntradas(cantidad);

    for(int i=0; i<cantidad; i++)
    {
        vecEntradas[i].mostrarEntrada();
    }
    delete[] vecEntradas;
}

void ManagerEntrada::mostrarEntradasPorDNI()
{
    int clienteDNI;
    mostrarEntradas();
    bool encontro=false;
    cout<< "INGRESE EL DNI CLIENTE QUE DESEA BUSCAR"<<endl;
    cin>> clienteDNI;

    int cantidadDeEntradas;
    Entrada* vecEntradas= cargarTodasLasEntradas(cantidadDeEntradas);

    for(int i=0; i<cantidadDeEntradas; i++)
    {
        if(vecEntradas[i].getDNIComprador()==clienteDNI)
        {
            vecEntradas[i].mostrarEntrada();
            encontro=true;
        }
    }
    if(!encontro)
    {
        cout<< "NO SE COMPRARON ENTRADAS CON ESE DNI"<<endl;
    }
    delete[] vecEntradas;
    system("pause");
    system("cls");
}

void ManagerEntrada::mostrarEntradasPorFecha()
{
    Fecha fechaABuscar;
    mostrarEntradas();
    bool encontro=false;
    fechaABuscar.cargarFecha();

    int cantidadDeEntradas;
    Entrada* vecEntradas= cargarTodasLasEntradas(cantidadDeEntradas);

    for(int i=0; i<cantidadDeEntradas; i++)
    {
        if(vecEntradas[i].getFechaDeProyeccion()==fechaABuscar)
        {
            vecEntradas[i].mostrarEntrada();
            encontro=true;
        }
    }
    if(!encontro)
    {
        cout<< "NO SE COMPRARON ENTRADAS EN ESA FECHA"<<endl;
    }
    delete[] vecEntradas;
    system("pause");
    system("cls");
}

void ManagerEntrada::mostrarEntradasPorPelicula()
{
    string peliculaABuscar;
    mostrarEntradas();
    bool encontro=false;
    cout<< "INGRESE EL NOMBRE DE LA PELICULA DE LA QUE DESEA VEN ENTRADAS: "<<endl;
    cin.ignore();
    getline(cin,peliculaABuscar);
    /// pasar a minusculas

    int cantidadDeEntradas;
    Entrada* vecEntradas= cargarTodasLasEntradas(cantidadDeEntradas);

    for(int i=0; i<cantidadDeEntradas; i++)
    {
        if(vecEntradas[i].getEntradaAPelicula()==peliculaABuscar)
        {
            vecEntradas[i].mostrarEntrada();
            encontro=true;
        }
    }
    if(!encontro)
    {
        cout<< "NO SE COMPRARON ENTRADAS PARA ESA PELICULA"<<endl;
    }
    delete[] vecEntradas;
    system("pause");
    system("cls");
}
