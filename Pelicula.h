#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include "Constante.h"
#include <string>
/*Por cada una de las pel�culas registra un n�mero de identificaci�n, el nombre de la
 pel�cula, el apellido y nombre del director, el g�nero de la pel�cula, la clasificaci�n
 de la pel�cula y la fecha de estreno. La clasificaci�n se refiere a qui�nes pueden acceder
 a verla (1: apta todo p�blico; 2: para mayores de 14 a�os; 3: para mayores de 18 a�os).*/
#include "Fecha.h"
class Pelicula{
public:
    Pelicula();
    Pelicula(int ID, string nombrePelicula,string nombreDirector,string apellidoDirector,string generoPelicula,string clasificacionPelicula,bool estado, Fecha fechaDeEstreno);
    void pasarAMinusculas(string &cadena);

    bool cargarPelicula();
    void setNumeroID(int numeroID);
    void setNombrePelicula(string nombrePelicula);
    void setNombreDelDirector(string nombreDirector);
    void setApellidoDelDirector(string apellidoDirector);
    void setGeneroPelicula(string generoPelicula);
    void setClasificacionPelicula(string clasificacionPelicula);///setCalisificacionPelicula se corrigio estaba mal escrito
    void setEstado(bool estado);
    void setFechaDeEstreno(Fecha fechaDeEstreno);/// setFechaDeEstrano se corrigio estaba mal escrito

    int getNumeroDeID();
    string getNombrePelicula();
    string getNombreDelDirector();
    string getApellidoDelDirector();
    string getGeneroPelicula();
    string getClasificacionPelicula();
    bool getEstado();
    Fecha getFechaDeEstreno();

private:
    int _peliculaID;
    char _nombrePelicula[TAMANIOCHARLARGO];
    char _nombreDelDirector[TAMANIOCHARMEDIO];
    char _apellidoDelDirector[TAMANIOCHARMEDIO];
    char _generoPelicula[TAMANIOCHARMEDIO];
    char _clasificacionPelicula[TAMANIOCHARMEDIO];
    Fecha _fechaDeEstreno;
    bool _estado;

};




#endif // PELICULA_H_INCLUDED
