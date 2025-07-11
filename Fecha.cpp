#include <iostream>
#include <limits>
using namespace std;
#include "Fecha.h"

Fecha::Fecha() {
    _dia=0;
    _mes=0;
    _anio=0;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
bool Fecha::cargarFecha()/// capaz con un bool deberia evitar q se guarde el objeto si la fecha no es valida o dejar de cargar datos
{
    int dia;
    int mes;
    int anio;
    int contadorDeErrores=0;
    bool esValida;
    do
    {
        cout<< "INGRESE EL DIA: "<<endl;
        dia=validarEntero();/// aca validamos que ingrese un entero

        cout<< "INGRESE EL MES: "<<endl;
        mes=validarEntero();

        cout<< "INGRESE EL ANIO: "<<endl;
        anio=validarEntero();

        esValida=esFechaValida(dia, mes, anio);/// aca validamos que la fecha sea correcta
        if(esValida)
        {
            setDia(dia);
            setMes(mes);
            setAnio(anio);
        }
        else
        {
            cout<< "INGRESO UN FECHA INCORRECTA, INTENTE CON UNA FECHA DISTINTA"<<endl;/// talvez podriamos mostrar cuantos intentos validos le quedan
            contadorDeErrores++;
        }

    }
    while(!esValida&&contadorDeErrores<3);

    return esValida;
}
void Fecha::mostrarFecha()
{
    cout<< getDia() << "/"<< getMes()<< "/"<< getAnio()<<endl;
}

bool Fecha::operator==(const Fecha& otra) const {
    return getDia()  == otra.getDia() && getMes()  == otra.getMes() && getAnio() == otra.getAnio();
}

int Fecha::validarEntero(){/// podrias mas adelante mandar el contador por referencia
    int entero;

    while (true) {
        cin >> entero;

        if (cin.fail()) {
            cout << "Entrada invalida. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Siempre limpiar el resto de la línea
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entero;
        }
    }
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

int Fecha::getDia()const
{
    return _dia;
}
int Fecha::getMes()const
{
    return _mes;
}
int Fecha::getAnio()const
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
