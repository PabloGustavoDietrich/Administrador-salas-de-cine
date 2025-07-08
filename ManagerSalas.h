#ifndef MANAGERSALAS_H_INCLUDED
#define MANAGERSALAS_H_INCLUDED
#include "Sala.h"
#include "ArchivoSala.h"

class ManagerSalas{
public:
   void CargarSala();
   void MostrarSalas();
   void MostrarSala(Sala reg);
   int buscarPosicionSalaPorNumero(int numeroSala=0);
   void bajaPorMantenimiento();
   void altaPostMantenimiento();
   void MostrarSalasActivas();
   void mostrarSalaPorNumero(int numeroSala);
   void mostrarSalaConNumero(int numeroSala,int& contadorDeSalasFueraDeServicio);
   bool validaEstadoSala(int numeroSala);
   bool comprarButaca(int numeroSala,int fila,int butaca); ///cambie de void a bool para el while de manager entradas
   int cantidadDeSalas();
private:
    ArchivoSala _archivoSalas;

} ;



#endif // MANAGERSALAS_H_INCLUDED
