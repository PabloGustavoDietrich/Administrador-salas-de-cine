#ifndef MANAGERENTRADA_H_INCLUDED
#define MANAGERENTRADA_H_INCLUDED
#include "ArchivoEntrada.h"

class ManagerEntrada{
public:
    void cargarEntrada();
    void mostrarEntradas();
    void mostrarEntradasPorDNI();
    void mostrarEntradasPorFecha();
    void mostrarEntradasPorPelicula();
    Entrada* cargarTodasLasEntradas(int& cantidad);
private:
    ArchivoEntrada _archiTikets;

};

#endif // MANAGERENTRADA_H_INCLUDED
