#ifndef ENTRADA_H_INCLUDED
#define ENTRADA_H_INCLUDED
#include <string>
#include <cstring>
#include "Constante.h"
#include "Fecha.h"
class Entrada{
public:

    Entrada();
    Entrada(int iDPelicula,int fila,int butacas,int cantEntradas,string entradaAPelicula,int numeroDeSala,Fecha fechaDeProyeccion,int dNiComprador,float precio);
    bool cargarEntradas(Entrada*& vec, int& cantidad);
    void mostrarEntrada();
    int validarEntero();


    void setEntradaAPelicula(string entradaAPelicula);
    void setNumeroDeSala(int numeroDeSala);
    void setFechaDeProyeccion(Fecha fechaDeProyeccion);
    void setDNIComprador(int dNIComprador);
    void setIDPelicula(int iDPelicula);
    void setFila(int fila);
    void setButacas(int butacas);
    void setCantEntradas(int cantEntradas);
    void setPrecio(float precio);

    int getIDPelicula();
    int getFila();
    int getButacas();
    int getCantEntradas();
    string getEntradaAPelicula();
    int getNumeroDeSala();
    Fecha getFechaDeProyeccion();
    int getDNIComprador();
    float getPrecio();

private:
    int _iDPelicula;//3
    int _fila;//6 se piden juntos
    int _butacas;//6 se piden juntos
    int _cantEntradas;//5
    char _entradaAPelicula[TAMANIOCHARMEDIO];// 3 se consigue con el ID de la pelicula
    int _numeroDeSala;//4
    Fecha _fechaDeProyeccion;//1 a la hora del proyecto validar q no se pueda comprar para ayer
    int _dNIComprador;//2
    float _precio;/// con la fecha y numero de sala sabes el tipo y por ende el precio
};

#endif // ENTRADA_H_INCLUDED
