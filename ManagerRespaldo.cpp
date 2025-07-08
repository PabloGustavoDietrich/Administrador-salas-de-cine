#include <iostream>
using namespace std;

#include "ManagerRespaldo.h"

void ManagerRespaldo::crearNuevoRespaldoEntradas()
{
    int cantidad;
    Entrada *vecEntradas;

    cantidad=_archiTikets.getCantidadDeEntradas();
    if(cantidad>0)
    {
        vecEntradas= new Entrada[cantidad];
        if (vecEntradas == nullptr)
        {
            cout << "No se pudo reservar memoria para las entradas." << endl;
            return;
        }/// se valido la obtencion de memoria

        _archiTikets.leerTodas(vecEntradas,cantidad);

        if(_archivoBackUP.respaldoEntradas(vecEntradas,cantidad))
        {
            cout<< "RESPALDO CREADO CON EXITO"<<endl;
        }

        delete[]vecEntradas;
    }
    else
    {
        cout<< "NO HAY ARCHIVOS PARA RESPALDAR"<<endl;
    }
    system("pause");
    system("cls");
}
void ManagerRespaldo::traerElRespaldoDeEntradas()
{
    int cantidad;
    Entrada *vecEntradas;

    cantidad=_archivoBackUP.getCantidadDeEntradasDeRespaldo();
    if(cantidad>0)
    {
        vecEntradas= new Entrada[cantidad];
        if (vecEntradas == nullptr)
        {
            cout << "No se pudo reservar memoria para las entradas." << endl;
            return;
        }/// se valido la obtencion de memoria

        _archivoBackUP.recuperarEntradas(vecEntradas,cantidad);

        if(_archiTikets.guardarEntradas(vecEntradas,cantidad))
        {
            cout<< "ENTRADAS RECUPERADAS CON EXITO"<<endl;
        }


        delete[]vecEntradas;
    }
    else
    {
        cout<< "NO HAY ENTRADAS PARA RECUPERAR"<<endl;
    }
    system("pause");
    system("cls");
}

void ManagerRespaldo::crearNuevoRespaldoPeliculas()
{
    int cantidad;
    Pelicula *vecPeliculas;

    cantidad=_archiPeli.getCantidadPeliculas();
    if(cantidad>0)
    {
        vecPeliculas= new Pelicula[cantidad];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las peliculas." << endl;
            return;
        }/// se valido la obtencion de memoria

        _archiPeli.leerTodas(vecPeliculas,cantidad);

        if(_archivoBackUP.respaldoPeliculas(vecPeliculas,cantidad))
        {
            cout<< "RESPALDO CREADO CON EXITO"<<endl;
        }

        delete[]vecPeliculas;
    }
    else
    {
        cout<< "NO HAY PELICULAS PARA RESPALDAR"<<endl;
    }
    system("pause");
    system("cls");
}
void ManagerRespaldo::traerElRespaldoDePeliculas()
{
    int cantidad;
    Pelicula *vecPeliculas;

    cantidad=_archivoBackUP.getCantidadDePeliculasDeRespaldo();
    if(cantidad>0)
    {
        vecPeliculas= new Pelicula[cantidad];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las peliculas." << endl;
            return;
        }/// se valido la obtencion de memoria

        _archivoBackUP.recuperarPeliculas(vecPeliculas,cantidad);

        if(_archiPeli.guardarPeliculas(vecPeliculas,cantidad))
        {
            cout<< "PELICULAS RECUPERADAS CON EXITO"<<endl;
        }
        delete[]vecPeliculas;
    }
    else
    {
        cout<< "NO HAY PELICULAS PARA RECUPERAR"<<endl;
    }
    system("pause");
    system("cls");
}

void ManagerRespaldo::crearNuevoRespaldoSalas()
{
    int cantidad;
    Sala *vecSalas;

    cantidad=_archivoSalas.getCantidadSalas();
    if(cantidad>0)
    {
        vecSalas= new Sala[cantidad];
        if (vecSalas == nullptr)
        {
            cout << "No se pudo reservar memoria para las salas." << endl;
            return;
        }/// se valido la obtencion de memoria

        _archivoSalas.leerTodas(vecSalas,cantidad);

        if(_archivoBackUP.respaldoSalas(vecSalas,cantidad))
        {
            cout<< "RESPALDO CREADO CON EXITO"<<endl;
        }
        delete[]vecSalas;
    }
    else
    {
        cout<< "NO HAY SALAS PARA RESPALDAR"<<endl;
    }
    system("pause");
    system("cls");
}
void ManagerRespaldo::traerElRespaldoDeSalas()
{
    int cantidad;
    Sala *vecSalas;

    cantidad=_archivoBackUP.getCantidadDeSalasDeRespaldo();
    if(cantidad>0)
    {

        vecSalas= new Sala[cantidad];
        if (vecSalas == nullptr)
        {
            cout << "No se pudo reservar memoria para las salas." << endl;
            return;
        }/// se valido la obtencion de memoria

        _archivoBackUP.recuperarSalas(vecSalas,cantidad);

        if(_archivoSalas.guardarSalas(vecSalas,cantidad))
        {
            cout<< "SALAS RECUPERADAS CON EXITO"<<endl;
        }
        delete[]vecSalas;
    }
    else
    {
        cout<< "NO HAY SALAS PARA RECUPERAR"<<endl;
    }
    system("pause");
    system("cls");
}
