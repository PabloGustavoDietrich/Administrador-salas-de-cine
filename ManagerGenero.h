#ifndef MANAGERGENERO_H_INCLUDED
#define MANAGERGENERO_H_INCLUDED
#include "Genero.h"
#include "ArchivoGenero.h"
class ManagerGenero{
public:
    void pausarYLimpiar();
    Genero* cargarTodosLosGeneros(int& cantidad);
    void cargarGenero();
    void mostrarGeneros();
    void mostrarGeneroPorCod();
    int buscarPosicionGeneroPorCod();
    void bajaGenero();
    void altaGenero();
    void mostrarPeliculasPorGenero();

private:
    ArchivoGenero _archiGenero;

};

#endif // MANAGERGENERO_H_INCLUDED
