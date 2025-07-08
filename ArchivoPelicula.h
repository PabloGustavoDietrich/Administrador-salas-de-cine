#ifndef ARCHIVOPELICULA_H_INCLUDED
#define ARCHIVOPELICULA_H_INCLUDED
///#include "ArchivoPelicula.H"
#include "Pelicula.h"
class ArchivoPelicula{
public:
    ArchivoPelicula(string nombreArchivo="Peliculas.dat");
    bool guardarPelicula(Pelicula reg);
    bool guardarPeliculas(Pelicula reg[],int cantidad);
    int getCantidadPeliculas();
    int getCantidadPeliculasEnCartelera();
    bool leerTodas(Pelicula reg[],int cantidad);
    bool bajaLogicaPelicula(Pelicula reg, int poscicion);
    bool altaLogicaPelicula(Pelicula reg, int poscicion);
private:
    string _nombreArchivo;
};

#endif // ARCHIVOPELICULA_H_INCLUDED
