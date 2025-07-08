#include <iostream>
using namespace std;
#include "Entrada.h"
#include <string>
#include <cstring>

Entrada::Entrada(){}

Entrada::Entrada(int iDPelicula,int fila,int butacas,int cantEntradas,string entradaAPelicula,int numeroDeSala,Fecha fechaDeProyeccion,int dNIComprador)
{
    setIDPelicula(iDPelicula);
    setFila(fila);
    setButacas(butacas);
    setCantEntradas(cantEntradas);
    setEntradaAPelicula(entradaAPelicula);
    setNumeroDeSala(numeroDeSala);
    setFechaDeProyeccion(fechaDeProyeccion);
    setDNIComprador(dNIComprador);
}
void Entrada::setEntradaAPelicula(string entradaAPelicula)
{
    strcpy(_entradaAPelicula,entradaAPelicula.c_str());
}
void Entrada::setNumeroDeSala(int numeroDeSala)
{
    _numeroDeSala=numeroDeSala;
}
void Entrada::setFechaDeProyeccion(Fecha fechaDeProyeccion)
{
    _fechaDeProyeccion=fechaDeProyeccion;
}
bool Entrada::setDNIComprador(int dNIComprador)
{
    if(dNIComprador>1000000){
    _dNIComprador=dNIComprador;
    return true;
    }else{
    return false;
    }
}

void Entrada::setIDPelicula(int iDPelicula)
{
    _iDPelicula=iDPelicula;
}
void Entrada::setFila(int fila)
{
    _fila=fila;
}
void Entrada::setButacas(int butacas)
{
    _butacas=butacas;
}
void Entrada::setCantEntradas(int cantEntradas)
{
    _cantEntradas=cantEntradas;
}

int Entrada::getIDPelicula()
{
    return _iDPelicula;
}
int Entrada::getFila()
{
    return _fila;
}
int Entrada::getButacas()
{
    return _butacas;
}
int Entrada::getCantEntradas()
{
    return _cantEntradas;
}

string Entrada::getEntradaAPelicula()
{
    return _entradaAPelicula;
}
int Entrada::getNumeroDeSala()
{
    return _numeroDeSala;
}
Fecha Entrada::getFechaDeProyeccion()
{
    return _fechaDeProyeccion;
}
int Entrada::getDNIComprador()
{
    return _dNIComprador;
}
