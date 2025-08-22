#ifndef ARCHIVORESPALDO_H_INCLUDED
#define ARCHIVORESPALDO_H_INCLUDED
#include "Entrada.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Clientes.h"
class ArchivoRespaldo{
public:
    bool respaldoEntradas(Entrada reg[],int cantidad);
    int getCantidadDeEntradasDeRespaldo();
    bool recuperarEntradas(Entrada reg[], int cantidad);
    bool respaldoPeliculas(Pelicula reg[],int cantidad);
    int getCantidadDePeliculasDeRespaldo();
    bool recuperarPeliculas(Pelicula reg[],int cantidad);
    bool respaldoSalas(Sala reg[],int cantidad);
    int getCantidadDeSalasDeRespaldo();
    bool recuperarSalas(Sala reg[],int cantidad);

    bool respaldoClientes(Clientes reg[], int cantidad);
    int getCantidadDeClientesRespaldo();
    bool recuperarClientes(Clientes reg[], int cantidad);
};

#endif // ARCHIVORESPALDO_H_INCLUDED
