#include <iostream>
using namespace std;
#include<cstring>
#include "Pelicula.h"
#include "ArchivoPelicula.h"
Pelicula::Pelicula() {}

Pelicula::Pelicula(int ID, string nombrePelicula,string nombreDirector,string apellidoDirector,string generoPelicula,string clasificacionPelicula,bool estado, Fecha fechaDeEstreno)
{
    setNumeroID();
    setNombrePelicula(nombrePelicula);
    setNombreDelDirector(nombreDirector);
    setApellidoDelDirector(apellidoDirector);
    setGeneroPelicula(generoPelicula);
    setClasificacionPelicula(clasificacionPelicula);
    setEstado(estado);
    setFechaDeEstreno(fechaDeEstreno);
}

void Pelicula::cargarPelicula(){
    string nombrePelicula;
    string nombreDelDirector;
    string apellidoDelDirector;
    string generoPelicula;
    string clasificacionPelicula;
    Fecha fechaDeEstreno;
    bool estado;

    setNumeroID();


}

void Pelicula::setNumeroID()
{
    int cantidadDePeliculas;
    ArchivoPelicula archivoPelicula;
    cantidadDePeliculas=archivoPelicula.getCantidadPeliculas();///nos guardamos el valor de la cantidad de pwliculas que hay
    if(cantidadDePeliculas<0) ///si no hay peliculas nos llega un -1
    {
        _peliculaID=1;
    }
    else
    {
        _peliculaID=cantidadDePeliculas+1;
    }
}
bool Pelicula::setNombrePelicula(string nombrePelicula)
{
    if (nombrePelicula.length() > 0 && nombrePelicula.length() < TAMANIOCHARMEDIO)// menor por lo del /0
    {
        strcpy(_nombrePelicula,nombrePelicula.c_str());
        return true;
    }
    return false;
}
bool Pelicula::setNombreDelDirector(string nombreDirector)
{
    if (nombreDirector.length() > 0 && nombreDirector.length() < TAMANIOCHARMEDIO)
    {
        strcpy(_nombreDelDirector,nombreDirector.c_str());
        return true;
    }
    return false;

}
bool Pelicula::setApellidoDelDirector(string apellidoDirector)
{
    if (apellidoDirector.length() > 0 && apellidoDirector.length() < TAMANIOCHARMEDIO)
    {
        strcpy(_apellidoDelDirector,apellidoDirector.c_str());
        return true;
    }
    return false;

}
bool Pelicula::setGeneroPelicula(string generoPelicula)
{
    if (generoPelicula.length() > 0 && generoPelicula.length() < TAMANIOCHARMEDIO)
    {
        strcpy(_generoPelicula,generoPelicula.c_str());
        return true;
    }
    return false;
}
bool Pelicula::setClasificacionPelicula(string clasificacionPelicula)
{
    if (clasificacionPelicula.length() > 0 && clasificacionPelicula.length() < TAMANIOCHARMEDIO)
    {
        strcpy(_clasificacionPelicula,clasificacionPelicula.c_str());
        return true;
    }
    return false;

}
void Pelicula::setFechaDeEstreno(Fecha fechaDeEstreno)
{
    _fechaDeEstreno=fechaDeEstreno;
}
void Pelicula::setEstado(bool estado)
{
    _estado=estado;
}

int Pelicula::getNumeroDeID()
{
    return _peliculaID;
}
string Pelicula::getNombrePelicula()
{
    return _nombrePelicula;
}
string Pelicula::getNombreDelDirector()
{
    return _nombreDelDirector;
}
string Pelicula::getApellidoDelDirector()
{
    return _apellidoDelDirector;
}
string Pelicula::getGeneroPelicula()
{
    return _generoPelicula;
}
string Pelicula::getClasificacionPelicula()
{
    return _clasificacionPelicula;
}
Fecha Pelicula::getFechaDeEstreno()
{
    return _fechaDeEstreno;
}

bool Pelicula::getEstado()
{
    return _estado;
}
