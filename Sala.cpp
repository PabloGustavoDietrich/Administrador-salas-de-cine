#include <iostream>
#include "Sala.h"
#include "Constante.h"
#include <cstring>

using namespace std;

Sala::Sala() {}

Sala::Sala(int numero,string nombre,int tipo,bool estadoSala)
{
    setnumero(numero);
    setnombre(nombre);
    settipo(tipo);
    setEstado(estadoSala);
    setButacas();
}

int Sala::getnumero()
{
    return _numero;
}

string Sala::getnombre()
{
    return _nombre;
}

int Sala::gettipo()
{
    return _tipo;
}

bool Sala::getEstadoSala()
{
    return _estadoSala;
}


bool Sala::getButaca(int fila,int columna)
{
    return _butacas[fila][columna];
}


void Sala::setButacas()
{
    for(int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            _butacas[i][j]=false;
        }
    }
}

void Sala::setButaca(int fila,int columna,bool estado)
{
    _butacas[fila][columna]=estado;
}

void Sala::setnumero(int numero)
{
    _numero=numero;
}

bool Sala::setnombre(string nombre)
{
    if (nombre.length() > 0 && nombre.length() < TAMANIOCHARMEDIO)// menor por lo del /0
    {
        strcpy(_nombre,nombre.c_str());
        return true;
    }
    return false;
}

bool Sala::settipo(int tipo)
{
    if(tipo>0&&tipo<4)
    {
        _tipo=tipo;
        return true;
    }
    return false;
}

void Sala::setEstado(bool estadoSala)
{
    _estadoSala=estadoSala;
}











