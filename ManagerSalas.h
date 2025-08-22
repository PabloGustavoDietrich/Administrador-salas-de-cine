#ifndef MANAGERSALAS_H_INCLUDED
#define MANAGERSALAS_H_INCLUDED
#include "Sala.h"
#include "ArchivoSala.h"

class ManagerSalas{
public:
    void pausarYLimpiar();
    void cargarSala();
    Sala* leerTodasLasSalas(int &cantidad);
    void mostrarSalas();
    int buscarPosicionSalaPorNumero();
    void mostrarSalaPorNumero();
    void mostrarSalasPorFecha();
    void mostrarSalasEstadoNYF();
    void bajaPorMantenimiento();
    void altaPostMantenimiento();
private:
    ArchivoSala _archivoSalas;

} ;

#endif // MANAGERSALAS_H_INCLUDED
