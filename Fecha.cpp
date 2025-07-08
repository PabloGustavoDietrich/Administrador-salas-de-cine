#include <iostream>
using namespace std;
#include "Fecha.h"

Fecha::Fecha() {}

Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
void Fecha::cargarFecha()/// capaz con un bool deberia evitar q se guarde el objeto si la fecha no es valida o dejar de cargar datos
{
    int dia;
    int mes;
    int anio;
    bool esValida;
    bool intento=false;
    do{
    cout<< "INGRESE EL DIA: "<<endl;
    cin>> dia;
    cout<< "INGRESE EL MES: "<<endl;
    cin>> mes;
    cout<< "INGRESE EL ANIO: "<<endl;
    cin>> anio;

    esValida=esFechaValida(dia, mes, anio);
    if(esValida){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    }else{
        cout<< "LA FECHA INGRESADA NO ES VALIDA, PRESIONE 1 SI DESEA CARGAR OTRA FECHA O 0 PARA SALIR"<<endl;
        cin>>intento;
    }

    }while(!esValida&&intento);

}
void Fecha::mostrarFecha(){
    cout<< _dia << "/"<< _mes<< "/"<< _anio<<endl;
}

bool Fecha::esFechaValida(int dia, int mes, int anio)
{

    // Rango de año aceptado
    if (anio < 1900 || anio > 2100)
    {
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        return false;
    }
    if (dia < 1)
    {
        return false;
    }

    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Verificar año bisiesto para febrero
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        diasPorMes[1] = 29;
    }

    if (dia > diasPorMes[mes - 1])
    {
        return false;
    }

    return true;
}

int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}
void Fecha::setDia(int dia)
{
    _dia=dia;
}
void Fecha::setMes(int mes)
{
    _mes=mes;
}
void Fecha::setAnio(int anio)
{
    _anio=anio;
}
