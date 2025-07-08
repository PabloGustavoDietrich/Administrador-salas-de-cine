#ifndef ARCHIVOENTRADA_H_INCLUDED
#define ARCHIVOENTRADA_H_INCLUDED
#include "Entrada.h"
#include <string>
class ArchivoEntrada
{
public:
    ArchivoEntrada(string nombreArchivo="Entradas.dat");
    bool guardarEntrada(Entrada reg);
    bool guardarEntradas(Entrada reg[],int cantidad);/// recuperadas del backup
    bool leerTodas(Entrada reg[],int cantidad);
    int getCantidadDeEntradas();
///    bool guardarEntradasCompradas(Entrada reg[],int cantidad);
private:
    string _nombreArchivo;
};

#endif // ARCHIVOENTRADA_H_INCLUDED
