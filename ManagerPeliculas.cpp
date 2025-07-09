#include <iostream>
using namespace std;
#include "ManagerPeliculas.h"
#include <cstring>

void ManagerPeliculas::cargarPelicula()
{
    Pelicula registro;
    if(registro.cargarPelicula())
    {
        cout<<"PELICULA CARGADA CON EXITO"<<endl;

        if(_archiPeli.guardarPelicula(registro))
        {
            cout<< "LA PELICULA SE GUARDO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<< "LA PELICULA NO SE PUDO GUARDAR"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void ManagerPeliculas::mostrarPeliculas()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();

    if(cantidadDePeliculas>0)
    {
        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return;
        }/// se valido la optencion de memoria

        if(_archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas))
        {
            for(int i=0; i<cantidadDePeliculas; i++)
            {
                vecPeliculas[i].mostrarPelicula();
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout<<"NO HAY PELICULAS PARA MOSTRAR"<<endl;
    }
    system("pause");
    system("cls");
}


/// funcion numero 3 del menu pelicula, ayuda con la funcion del menu 4 y menu 5
int ManagerPeliculas::buscarPosicionPeliculaPorID()
{
    int ID;
    int posicion=-1;
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    if(cantidadDePeliculas>0)
    {

        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return -1;
        }/// se valido la optencion de memoria

        _archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas);

        cout<< "INGRESE EL ID DE LA PELICULA: "<<endl;
        cin>>ID;

        for(int i=0; i<cantidadDePeliculas; i++)
        {
            if(ID==vecPeliculas[i].getNumeroDeID())
            {
                delete[] vecPeliculas;
                posicion=i;
                return posicion;
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout<<"NO HAY PELICULA PARA BUSCAR"<<endl;
    }
    system("pause");
    system("cls");
    return posicion;
}

/// OPCION 4 DEL MENU DE PELICULAS
void ManagerPeliculas::sacarDeCartelera()
{
    int posicion;
    Pelicula registro;
    ///MOSTRAMOS EL LISTADO DE PELICULAS QUE ESTAN EN CARTELERA
    mostrarPeliculasEnCartelera();

    posicion=buscarPosicionPeliculaPorID();
    if(posicion!= -1) /// si el valor de posicion fuese -1 quiere decir que no se encontro una posicion para la pelicula;
    {
        if(_archiPeli.bajaLogicaPelicula(registro, posicion))
        {
            cout<< "LA PELICULA FUE QUITADA CON EXITO"<<endl;
        }
        else
        {
            cout<< "LA PELICULA NO ESTABA EN CARTELERA"<<endl;
        }
        system("pause");
        system("cls");
    }
}
/// OPCION 5 DEL MENU DE PELICULAS
void ManagerPeliculas::ponerEnCartelera()
{
    int posicion;
    Pelicula registro;

    ///MOSTRAMOS EL LISTADO DE PELICULAS QUE NO ESTAN EN CARTELERA
    mostrarPeliculasSinCartelera();

    posicion=buscarPosicionPeliculaPorID();

    if(posicion!= -1) /// si el valor de posicion fuese -1 quiere decir que no se encontro una posicion para la pelicula;
    {
        if(_archiPeli.altaLogicaPelicula(registro, posicion))
        {
            cout<< "LA PELICULA FUE AGREGADA CON EXITO"<<endl;
        }
        else
        {
            cout<< "LA PELICULA YA ESTABA EN CARTELERA"<<endl;
        }
        system("pause");
        system("cls");
    }
}



/// ESTA FUNCION LA USAMOS EN LA OPCION 6 DEL MENU DE PELICULAS
void ManagerPeliculas::mostrarPeliculasEnCartelera()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
/// ----> conseguimos los datos necesarios
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    if(cantidadDePeliculas>0)
    {
        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return;
        }/// se valido la optencion de memoria
        _archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas);
        {
            /// falta validar si consiguio memoria
            for(int i=0; i<cantidadDePeliculas; i++)
            {
                if(vecPeliculas[i].getEstado())
                {
                    vecPeliculas[i].mostrarPeliculaIDYCartelera();
                }
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout << "NO SE PUDIERON LEER LAS PELICULAS" << endl;
    }
}
/// con esta funcion ayudamos en la opcion 5 del menu para tener una idea de que pelicula poner en cartelera
void ManagerPeliculas::mostrarPeliculasSinCartelera()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
/// ----> conseguimos los datos necesarios
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    if(cantidadDePeliculas>0)
    {
        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return;
        }/// se valido la optencion de memoria
        _archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas);
        {
            /// falta validar si consiguio memoria
            for(int i=0; i<cantidadDePeliculas; i++)
            {
                if(!vecPeliculas[i].getEstado())
                {
                    vecPeliculas[i].mostrarPeliculaIDYCartelera();
                }
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout << "NO SE PUDIERON LEER LAS PELICULAS" << endl;
    }
}

/// FUNCION PARA USAR EN LA COMPRA DE ENTRADAS
Pelicula* ManagerPeliculas::traerPeliculasEnCartelera()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    int cantidadDePeliculasEnCartelera;
    Pelicula *vecPeliculas;
    Pelicula *vecPeliCartelera;/// memoria dinamica para eliminar en la otra funcion
    int pos=0;
/// ----> conseguimos los datos necesarios
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    cantidadDePeliculasEnCartelera=_archiPeli.getCantidadPeliculasEnCartelera();
    vecPeliculas=new Pelicula[cantidadDePeliculas];
    if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
        }/// se valido la obtencion de memoria
    vecPeliCartelera=new Pelicula[cantidadDePeliculasEnCartelera];
    if (vecPeliCartelera == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
        }/// se valido la obtencion de memoria
    if(_archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas))
    {
        /// falta validar si consiguio memoria
        for(int i=0; i<cantidadDePeliculas; i++)
        {
            if(vecPeliculas[i].getEstado())
            {
                vecPeliCartelera[pos]=vecPeliculas[i];
                pos++;
            }
        }
    }
    else
    {
        cout << "NO SE PUDIERON LEER LAS PELICULAS" << endl;
    }
    delete[] vecPeliculas;
    return vecPeliCartelera;
}
/// retornar la cantidad de peliculas que hay en cartelera
int ManagerPeliculas::cantidadPeliculasEnCartelera()
{
    int cantidadDePeliculasEnCartelera;
    cantidadDePeliculasEnCartelera=_archiPeli.getCantidadPeliculasEnCartelera();
    return cantidadDePeliculasEnCartelera;
}

