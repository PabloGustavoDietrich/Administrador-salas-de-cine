#include <iostream>
using namespace std;
#include "Genero.h"
#include <cstring>
#include "ArchivoGenero.h"
Genero::Genero() {}

Genero::Genero(int codGenero,string nombreGenero,bool estado)
{
    setCodGenero(codGenero);
    setNombreGenero(nombreGenero);
    setEstado(estado);
}
bool Genero::cargarGenero()
{
    string nombreGenero;
    bool esValida;
    int contadorDeErrores=0;
    int cantidadDeGeneros;
    ArchivoGenero archivoGenero;

    cantidadDeGeneros=archivoGenero.getCantidadGeneros();
    Genero* vecGeneros;

    if(cantidadDeGeneros<0)
    {
        setCodGenero(1);
    }
    else
    {
        setCodGenero(cantidadDeGeneros+1);
        vecGeneros=new Genero[cantidadDeGeneros];
        archivoGenero.leerTodas(vecGeneros,cantidadDeGeneros);
    }

    while(contadorDeErrores<3)
    {
        cout<< "INGRESE EL GENERO: "<<endl;
        getline(cin,nombreGenero);
        pasarAMinusculas(nombreGenero);
        bool encontro=false;
        if(cantidadDeGeneros>0)
        {
            for(int i=0; i<cantidadDeGeneros; i++)
            {
                if(vecGeneros[i].getNombreGenero()==nombreGenero)
                {
                    encontro=true;
                }
            }
        }
        esValida=nombreGenero.length() > 0 && nombreGenero.length() < TAMANIOCHARMEDIO && !encontro;
        if(esValida)
        {
            setNombreGenero(nombreGenero);
            break;
        }
        else
        {
            cout<< "INGRESO UN GENERO INCORRECTO"<<endl;
            contadorDeErrores++;
        }

    }
    setEstado(true);/// si lo estamos creando es porque seteamos a true por defecto

    if(cantidadDeGeneros>0)
    {
        delete[] vecGeneros;
    }
    return contadorDeErrores<3;
}
void Genero::pasarAMinusculas(string &cadena)
{
    for (char &caracter : cadena)
    {
        caracter = tolower(static_cast<unsigned char>(caracter));
    }
}


void Genero::mostrarGenero()
{
    cout<< "-------------------------------------------"<<endl;
    cout<< "EL COD. DEL GENERO ES: "<< getCodGenero()<<endl;
    cout<< "LA CATEGORIA ES: "<< getNombreGenero()<<endl;
    if(getEstado())cout<< "EL GENERO ESTA DISPONIBLE PARA NUEVAS PELICULAS"<<endl;
    if(!getEstado())cout<< "EL GENERO NO ESTA DISPONIBLE PARA NUEVAS PELICULAS"<<endl;
}

void Genero::setCodGenero(int codGenero)
{
    _codGenero=codGenero;
}
void Genero::setNombreGenero(string nombreGenero)
{
    strcpy(_nombreGenero,nombreGenero.c_str());
}
void Genero::setEstado(bool estado)
{
    _estado=estado;
}

int Genero::getCodGenero()
{
    return _codGenero;
}
string Genero::getNombreGenero()
{
    return _nombreGenero;
}
bool Genero::getEstado()
{
    return _estado;
}
