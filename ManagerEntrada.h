#ifndef MANAGERENTRADA_H_INCLUDED
#define MANAGERENTRADA_H_INCLUDED
#include "ArchivoEntrada.h"

class ManagerEntrada{
public:
    void cargarEntrada();
    void mostrarEntradas();
    void mostrarSoloPorCliente();
    void mostrarEntrada(Entrada reg);
private:
    ArchivoEntrada _archiTikets;

};

#endif // MANAGERENTRADA_H_INCLUDED
