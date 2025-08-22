#include <iostream>
using namespace std;
#include "ManagerGenero.h"
#include "ArchivoPelicula.h"

void ManagerGenero::pausarYLimpiar()
{
    system("pause");
    system("cls");
}
Genero* ManagerGenero::cargarTodosLosGeneros(int& cantidad)
{
    cantidad = _archiGenero.getCantidadGeneros();
    if(cantidad <= 0)
    {
        cout << "NO HAY GENEROS PARA MOSTRAR" << endl;
        return nullptr;
    }

    Genero* vec = new Genero[cantidad];
    if(vec == nullptr)
    {
        cout << "No se pudo reservar memoria para los generos." << endl;
        return nullptr;
    }

    if(!_archiGenero.leerTodas(vec, cantidad))
    {
        cout << "NO SE PUDIERON LEER LOS GENEROS" << endl;
        delete[] vec;
        return nullptr;
    }
    return vec;
}
///OPCION 1 DEL MENU
void ManagerGenero::cargarGenero()
{
    Genero registro;
    if(registro.cargarGenero())
    {
        cout<<"CARGADO EL GENERO CON EXITO"<<endl;
        if(_archiGenero.guardarGenero(registro))
        {
            cout<<"EL GENERO FUE GUARDADO CON EXITO"<<endl;
        }
        else
        {
            cout<<"NO SE PUDO GUARDAR EL GENERO"<<endl;
        }

    }
    else
    {
        cout<<"NO SE CARGO EL GENERO"<<endl;
    }
    pausarYLimpiar();
}
///OPCION 2 DEL MENU
void ManagerGenero::mostrarGeneros()
{
    int cantidad;
    Genero* vecGenero=cargarTodosLosGeneros(cantidad);
    if(!vecGenero)return;

    for(int i=0; i<cantidad; i++)
    {
        vecGenero[i].mostrarGenero();
    }
    delete[] vecGenero;
    ///pausarYLimpiar();
}

int ManagerGenero::buscarPosicionGeneroPorCod()
{
    int cantidad;
    Genero* vecGenero = cargarTodosLosGeneros(cantidad);
    if(!vecGenero) return -1;

    int codGenero;
    cout << "------------------------------------------" << endl;
    cout << "INGRESE EL CODIGO DEL GENERO: ";
    cin >> codGenero;/// validar la espera de un entero

    for(int i = 0; i < cantidad; i++)
    {
        if(codGenero == vecGenero[i].getCodGenero())
        {
            delete[] vecGenero;
            return i;
        }
    }

    delete[] vecGenero;
    cout << "ESE CODIGO GENERO NO EXISTE" << endl;
    return -1;
}
///OPCION 3 DEL MENU
void ManagerGenero::mostrarGeneroPorCod()
{
    int cantidad;
    Genero* vec = cargarTodosLosGeneros(cantidad);
    if(!vec)
    {
        pausarYLimpiar();
        return;
    }

    for(int i = 0; i < cantidad; i++)
    {
        vec[i].mostrarGenero();
    }

    int pos = buscarPosicionGeneroPorCod();
    if(pos != -1)
    {
        vec[pos].mostrarGenero();
    }
    delete[] vec;
    pausarYLimpiar();
}

///OPCION 4 DEL MENU
void ManagerGenero::bajaGenero()
{
    mostrarGeneros();
    int pos = buscarPosicionGeneroPorCod();

    if(pos != -1)
    {
        Genero registro;
        if(_archiGenero.bajaLogicaGenero(registro, pos))
        {
            cout << "EL GENERO FUE QUITADO CON EXITO" << endl;
        }
        else
        {
            cout << "EL GENERO NO ESTABA ACTIVO" << endl;
        }
    }
    pausarYLimpiar();
}
///OPCION 5 DEL MENU
void ManagerGenero::altaGenero()
{
    mostrarGeneros();
    int pos = buscarPosicionGeneroPorCod();

    if(pos != -1)
    {
        Genero registro;
        if(_archiGenero.altaLogicaGenero(registro, pos))
        {
            cout << "EL GENERO FUE AGREGADO CON EXITO" << endl;
        }
        else
        {
            cout << "EL GENERO YA ESTABA ACTIVO" << endl;
        }
    }
    pausarYLimpiar();
}
///OPCION 6 DEL MENU
void ManagerGenero::mostrarPeliculasPorGenero()
{
    mostrarGeneros();
    int pos= buscarPosicionGeneroPorCod();
    if(pos==-1)
    {
        pausarYLimpiar();
        return;
    }
    Genero registro;
    if(!_archiGenero.leerGenero(registro,pos))
    {
        cout<< "NO SE PUDO LEER EL REGISTRO"<<endl;
        return;
    }
    ArchivoPelicula archivoPelicula;
    Pelicula* vecPeliculas;
    int cantidadPeliculas=archivoPelicula.getCantidadPeliculas();

    if(cantidadPeliculas<0)
    {
        return;
    }
    vecPeliculas=new Pelicula[cantidadPeliculas];
    if(!vecPeliculas)
    {
        return;
    }

    archivoPelicula.leerTodas(vecPeliculas,cantidadPeliculas);

    for(int i=0; i<cantidadPeliculas; i++)
    {
        if(vecPeliculas[i].getGeneroPelicula()==registro.getNombreGenero())
        {
            vecPeliculas[i].mostrarPelicula();
        }
    }

    delete[] vecPeliculas;
    pausarYLimpiar();
}
