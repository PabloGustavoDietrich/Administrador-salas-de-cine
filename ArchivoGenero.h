#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

#include "Genero.h"
class ArchivoGenero{
public:
    ArchivoGenero(string nombreArchivo="Genero.dat");
    bool guardarGenero(Genero reg);
    int getCantidadGeneros();
    bool leerTodas(Genero reg[],int cantidad);
    bool leerGenero(Genero &reg,int posicion);
    bool bajaLogicaGenero(Genero reg, int poscicion);
    bool altaLogicaGenero(Genero reg, int poscicion);
private:
    string _nombreArchivo;
};
#endif // ARCHIVOGENERO_H_INCLUDED
