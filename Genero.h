#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED
#include "Constante.h"

class Genero{
public:
    Genero();
    Genero(int codGenero,string nombreGenero,bool estado);
    bool cargarGenero();
    void mostrarGenero();
    void pasarAMinusculas(string &cadena);

    void setCodGenero(int codGenero);
    void setNombreGenero(string nombreGenero);
    void setEstado(bool estado);

    int getCodGenero();
    string getNombreGenero();
    bool getEstado();

private:
    int _codGenero;
    char _nombreGenero[TAMANIOCHARMEDIO];
    bool _estado;
};
#endif // GENERO_H_INCLUDED
