#ifndef ARCHIVOSALA_H_INCLUDED
#define ARCHIVOSALA_H_INCLUDED
#include "Sala.h"
#include <string>

using namespace std;

class ArchivoSala{
public:
      ArchivoSala(string nombreArchivoSala="Salas.dat");
      bool guardarSala(Sala reg);
      bool guardarSalas(Sala reg[],int cantidad);
      int getCantidadSalas();
      bool leerTodas(Sala reg[],int cantidad);
      bool leerSala(Sala &reg,int posicion);
      bool bajaLogicaSala(Sala reg, int posicion);
      bool altaLogicaSala(Sala reg, int posicion);
      bool ocuparButaca(int numeroSala,int fila,int butaca);
      bool liberarButaca(int numeroSala,int fila,int butaca);

      int getCantidadSalasPorFecha(Fecha fechaDeProyeccion);
      void leerSalasDisponiblesPorFecha(Sala reg[],Fecha fechaAsignada);
private:
    string _nombreArchivoSala;
};













#endif // ARCHIVOSALA_H_INCLUDED
