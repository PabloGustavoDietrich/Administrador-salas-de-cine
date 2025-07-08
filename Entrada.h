#ifndef ENTRADA_H_INCLUDED
#define ENTRADA_H_INCLUDED
#include <string>
#include <cstring>
#include "Constante.h"
#include "Fecha.h"
class Entrada{
public:

    Entrada();
    Entrada(int iDPelicula,int fila,int butacas,int cantEntradas,string entradaAPelicula,int numeroDeSala,Fecha fechaDeProyeccion,int dNiComprador);

    void setEntradaAPelicula(string entradaAPelicula);
    void setNumeroDeSala(int numeroDeSala);
    void setFechaDeProyeccion(Fecha fechaDeProyeccion);
    bool setDNIComprador(int dNIComprador);
    void setIDPelicula(int iDPelicula);
    void setFila(int fila);
    void setButacas(int butacas);
    void setCantEntradas(int cantEntradas);


    int getIDPelicula();
    int getFila();
    int getButacas();
    int getCantEntradas();
    string getEntradaAPelicula();
    int getNumeroDeSala();
    Fecha getFechaDeProyeccion();
    int getDNIComprador();

private:
    int _iDPelicula;
    int _fila;
    int _butacas;
    int _cantEntradas;
    char _entradaAPelicula[TAMANIOCHARMEDIO];
    int _numeroDeSala;
    Fecha _fechaDeProyeccion;
    int _dNIComprador;

};

#endif // ENTRADA_H_INCLUDED
