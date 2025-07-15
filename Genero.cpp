#include <iostream>
using namespace std;
#include "Genero.h"
#include <cstring>

Genero::Genero(){}

Genero::Genero(int codGenero,string nombreGenero,bool estado){
setCodGenero(codGenero);
setNombreGenero(nombreGenero);
setEstado(estado);
}
bool Genero::cargarGenero(){
    int codGenero;
    string nombreGenero;
    bool estado;
    bool esValida;
    int contadorDeErrores=0;

    do
    {
        ///proximamente autoIncremental
        setCodGenero(1);

        cout<< "INGRESE EL GENERO: "<<endl;
        getline(cin,nombreGenero);

        esValida=true;///hasta crear la clase archivo y manager forzamos el true;
        if(esValida)
        {
            setNombreGenero(nombreGenero);
        }
        else
        {
            cout<< "INGRESO UN GENERO INCORRECTO"<<endl;
            contadorDeErrores++;
        }
        setEstado(true);/// si lo estamos creando es porque seteamos a true por defecto

    }
    while(!esValida&&contadorDeErrores<3);

}


void Genero::mostrarGenero(){
    cout<< "LA CATEGORIA ES: "<< getNombreGenero();
}

void Genero::setCodGenero(int codGenero){
    _codGenero=codGenero;
}
void Genero::setNombreGenero(string nombreGenero){
    strcpy(_nombreGenero,nombreGenero.c_str());
}
void Genero::setEstado(bool estado){
    _estado=estado;
}

int Genero::getCodGenero(){
    return _codGenero;
}
string Genero::getNombreGenero(){
    return _nombreGenero;
}
bool Genero::getEstado(){
    return _estado;
}
