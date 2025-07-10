#ifndef MANAGERPELICULAS_H_INCLUDED
#define MANAGERPELICULAS_H_INCLUDED
#include "Pelicula.h"
#include "ArchivoPelicula.h"
#include <string>
class ManagerPeliculas{
public:
    void pausarYLimpiar();
    Pelicula* cargarTodasLasPeliculas(int& cantidad);
    void cargarPelicula();
    void mostrarPeliculas();
    void mostrarPeliculasCartelera(bool enCartelera);
    void mostrarPeliculasEnCartelera();
    void mostrarPeliculasSinCartelera();
    int buscarPosicionPeliculaPorID();
    void mostrarPeliculasPorID();
    void sacarDeCartelera();
    void ponerEnCartelera();
    Pelicula* traerPeliculasEnCartelera();/// verificar utilidad
    int cantidadPeliculasEnCartelera();///posible funcion a eliminar

private:
    ArchivoPelicula _archiPeli;

};

#endif // MANAGERPELICULAS_H_INCLUDED
