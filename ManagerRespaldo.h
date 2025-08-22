#ifndef MANAGERRESPALDO_H_INCLUDED
#define MANAGERRESPALDO_H_INCLUDED
#include "ArchivoEntrada.h"
#include "ArchivoPelicula.H"
#include "ArchivoRespaldo.h"
#include "ArchivoSala.h"
#include "ArchivoClientes.h"

class ManagerRespaldo{
public:

    void crearNuevoRespaldoEntradas();
    void traerElRespaldoDeEntradas();
    void crearNuevoRespaldoPeliculas();
    void traerElRespaldoDePeliculas();
    void crearNuevoRespaldoSalas();
    void traerElRespaldoDeSalas();
    void crearNuevoRespaldoClientes();
    void traerElRespaldoDeClientes();

private:
    ArchivoPelicula _archiPeli;
    ArchivoEntrada _archiTikets;
    ArchivoSala _archivoSalas;
    ArchivoRespaldo _archivoBackUP;
    ArchivoClientes _archivoClientes;
};
#endif // MANAGERRESPALDO_H_INCLUDED
