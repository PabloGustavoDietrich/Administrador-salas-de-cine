#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "ArchivoEntrada.h"
#include "ArchivoPelicula.h"
#include "ArchivoSala.h"
#include "ArchivoGenero.h"
class Informes{
    public:
    void mostrarCantidadDeEntradasVendidas();
    void mostrarCantidadEntradasVendidasPorgenero();
    void mostrarCantidadDeEntradasVendidasPorTitulo();
    void mostrarCantidadDeEntradasVendidasPorTipoDeSala();
    void mostrarRecaudacion();
    private:
    ArchivoEntrada _archivoEntrada;
    ArchivoPelicula _archivoPelicula;
    ArchivoSala _archivoSala;
    ArchivoGenero _archivoGenero;
};

#endif // INFORMES_H_INCLUDED
