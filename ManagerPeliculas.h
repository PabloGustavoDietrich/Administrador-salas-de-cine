#ifndef MANAGERPELICULAS_H_INCLUDED
#define MANAGERPELICULAS_H_INCLUDED
#include "Pelicula.h"
#include "ArchivoPelicula.h"
#include <string>
class ManagerPeliculas{
public:
    void cargarPelicula();
    void mostrarPeliculas();
    void mostrarPeliculasPorID();
    int buscarPosicionPeliculaPorID();
    void sacarDeCartelera();
    void ponerEnCartelera();
    Pelicula* traerPeliculasEnCartelera();
    void mostrarPeliculasEnCartelera();
    void mostrarPeliculasSinCartelera();
    int cantidadPeliculasEnCartelera();
    bool verificarSiExiste(string nombrePelicula);
private:
    ArchivoPelicula _archiPeli;

};

#endif // MANAGERPELICULAS_H_INCLUDED
