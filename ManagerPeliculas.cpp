#include <iostream>
using namespace std;
#include "ManagerPeliculas.h"
#include <cstring>

void ManagerPeliculas::pausarYLimpiar() {
    system("pause");
    system("cls");
}

Pelicula* ManagerPeliculas::cargarTodasLasPeliculas(int& cantidad) {
    cantidad = _archiPeli.getCantidadPeliculas();
    if(cantidad <= 0) {
        cout << "NO HAY PELICULAS PARA MOSTRAR" << endl;
        return nullptr;
    }

    Pelicula* vec = new Pelicula[cantidad];
    if(vec == nullptr) {
        cout << "No se pudo reservar memoria para las películas." << endl;
        return nullptr;
    }

    if(!_archiPeli.leerTodas(vec, cantidad)) {
        cout << "NO SE PUDIERON LEER LAS PELICULAS" << endl;
        delete[] vec;
        return nullptr;
    }

    return vec;
}

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
    pausarYLimpiar();
}
void ManagerPeliculas::mostrarPeliculas() {
    int cantidad;
    Pelicula* vec = cargarTodasLasPeliculas(cantidad);
    if(!vec) return;

    for(int i = 0; i < cantidad; i++) {
        vec[i].mostrarPelicula();
    }
    delete[] vec;
    pausarYLimpiar();
}
void ManagerPeliculas::mostrarPeliculasCartelera(bool enCartelera) {
    int cantidad;
    Pelicula* vec = cargarTodasLasPeliculas(cantidad);
    if(!vec) return;

    for(int i = 0; i < cantidad; i++) {
        if(vec[i].getEstado() == enCartelera) {
            vec[i].mostrarPeliculaIDYCartelera();
        }
    }
    delete[] vec;
}
void ManagerPeliculas::mostrarPeliculasEnCartelera() {
    mostrarPeliculasCartelera(true);
}

void ManagerPeliculas::mostrarPeliculasSinCartelera() {
    mostrarPeliculasCartelera(false);
}

void ManagerPeliculas::mostrarPeliculasPorID() {
    int cantidad;
    Pelicula* vec = cargarTodasLasPeliculas(cantidad);
    if(!vec) return;

    for(int i = 0; i < cantidad; i++) {
        vec[i].mostrarPeliculaYID();
    }

    int pos = buscarPosicionPeliculaPorID();
    if(pos != -1) {
        vec[pos].mostrarPeliculaYID();
    }

    delete[] vec;
    pausarYLimpiar();
}

////ayuda con la funcion del menu 3, menu 4 y menu 5
int ManagerPeliculas::buscarPosicionPeliculaPorID() {
    int cantidad;
    Pelicula* vec = cargarTodasLasPeliculas(cantidad);
    if(!vec) return -1;

    int ID;
    cout << "------------------------------------------" << endl;
    cout << "INGRESE EL ID DE LA PELICULA: ";
    cin >> ID;

    for(int i = 0; i < cantidad; i++) {
        if(ID == vec[i].getNumeroDeID()) {
            delete[] vec;
            return i;
        }
    }

    delete[] vec;
    cout << "ESE ID NO EXISTE" << endl;
    return -1;
}

/// OPCION 4 DEL MENU DE PELICULAS
void ManagerPeliculas::sacarDeCartelera() {
    mostrarPeliculasEnCartelera();
    int pos = buscarPosicionPeliculaPorID();

    if(pos != -1) {
        Pelicula registro;
        if(_archiPeli.bajaLogicaPelicula(registro, pos)) {
            cout << "LA PELICULA FUE QUITADA CON EXITO" << endl;
        } else {
            cout << "LA PELICULA NO ESTABA EN CARTELERA" << endl;
        }
    }
    pausarYLimpiar();
}
/// OPCION 5 DEL MENU DE PELICULAS
void ManagerPeliculas::ponerEnCartelera() {
    mostrarPeliculasSinCartelera();
    int pos = buscarPosicionPeliculaPorID();

    if(pos != -1) {
        Pelicula registro;
        if(_archiPeli.altaLogicaPelicula(registro, pos)) {
            cout << "LA PELICULA FUE AGREGADA CON EXITO" << endl;
        } else {
            cout << "LA PELICULA YA ESTABA EN CARTELERA" << endl;
        }
    }
    pausarYLimpiar();
}

/// FUNCION PARA USAR EN LA COMPRA DE ENTRADAS
Pelicula* ManagerPeliculas::traerPeliculasEnCartelera() {
    int total, enCartelera;
    total = _archiPeli.getCantidadPeliculas();
    enCartelera = _archiPeli.getCantidadPeliculasEnCartelera();

    Pelicula* todas = cargarTodasLasPeliculas(total);
    if(!todas) return nullptr;

    Pelicula* cartelera = new Pelicula[enCartelera];
    if(cartelera == nullptr) {
        cout << "No se pudo reservar memoria para las películas." << endl;
        delete[] todas;
        return nullptr;
    }

    int pos = 0;
    for(int i = 0; i < total; i++) {
        if(todas[i].getEstado()) {
            cartelera[pos++] = todas[i];
        }
    }

    delete[] todas;
    return cartelera;
}
/// retornar la cantidad de peliculas que hay en cartelera
int ManagerPeliculas::cantidadPeliculasEnCartelera() {
    return _archiPeli.getCantidadPeliculasEnCartelera();
}

