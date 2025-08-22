#include <iostream>
using namespace std;
#include "Entrada.h"
#include <string>
#include <cstring>
#include <limits>
#include "ArchivoPelicula.h"
#include "ArchivoSala.h"
#include "Pelicula.h"
#include "ArchivoClientes.h"

Entrada::Entrada() {}

Entrada::Entrada(int iDPelicula,int fila,int butacas,int cantEntradas,string entradaAPelicula,int numeroDeSala,Fecha fechaDeProyeccion,int dNIComprador,float precio)
{
    setIDPelicula(iDPelicula);
    setFila(fila);
    setButacas(butacas);
    setCantEntradas(cantEntradas);
    setEntradaAPelicula(entradaAPelicula);
    setNumeroDeSala(numeroDeSala);
    setFechaDeProyeccion(fechaDeProyeccion);
    setDNIComprador(dNIComprador);
    setPrecio(precio);
}

bool Entrada::cargarEntradas(Entrada*& vecEntradas, int& cantidadCompradas)
{
    Fecha fechaDeProyeccion;
    int iDPelicula;
    string entradaAPelicula;
    int numeroDeSala;
    int dNIComprador;
    int cantidadDeEntradas;
    int fila;
    int butacas;
    float precio;
    int contadorDeErrores=0;

    ArchivoPelicula archivoPelicula;
    int cantidadPeliculasEnCartelera=archivoPelicula.getCantidadPeliculasEnCartelera();
    if (cantidadPeliculasEnCartelera<0)
    {
        cout<<"NO HAY PELICULAS EN CARTELERA"<<endl;
        return false;
    }

    ArchivoSala archivoSala;
    int cantidadDeSalas;
    while(contadorDeErrores<3)
    {
        fechaDeProyeccion.cargarFecha();

        Fecha fechaDeHoy;
        fechaDeHoy.setHoy();

        /// cuando carguemos los datos usar operador para no permitir comprar entrada de ayer, crear fecha de hoy
        cantidadDeSalas=archivoSala.getCantidadSalasPorFecha(fechaDeProyeccion);/// salas disponibles
        /// setear la fecha de hoy y comparar si es menor, esta queriendo comprar una entrada para ayer
        if(cantidadDeSalas>0 && !(fechaDeProyeccion<fechaDeHoy))
        {
            setFechaDeProyeccion(fechaDeProyeccion);
            contadorDeErrores=0;
            break;
        }
        else
        {
            if(fechaDeProyeccion<fechaDeHoy)
            {
                cout<< "ES UNA FECHA INVALIDA O DE AYER"<<endl;
            }
            if(cantidadDeSalas<=0)
            {
                cout<< "PARA LA FECHA ELEGIDA NO HAY SALAS DISPONIBLES"<<endl;
            }
            contadorDeErrores++;
        }

    }
    Pelicula* vecPeliculas;
    vecPeliculas=new Pelicula[cantidadPeliculasEnCartelera];
    if(!vecPeliculas)
    {
        return false;
    }
    archivoPelicula.leerPeliculasEnCartelera(vecPeliculas);

    Sala* vecSalas;
    vecSalas=new Sala[cantidadDeSalas];
    if(!vecSalas)
    {
        return false;
    }
    archivoSala.leerSalasDisponiblesPorFecha(vecSalas,fechaDeProyeccion);
    int encontro;
    while(contadorDeErrores<3)
    {
        encontro=-1;
        /// MUESTRA DE CARTELERA
        for(int i=0; i<cantidadPeliculasEnCartelera; i++)
        {
            vecPeliculas[i].mostrarPeliculaYID();
        }
        cout<< "INGRESE EL ID DE LA PALICULA QUE DESEE VER"<<endl;
        iDPelicula=validarEntero();/// revisar validar entero funcione bien;

        for(int i=0; i<cantidadPeliculasEnCartelera; i++)
        {
            if(vecPeliculas[i].getNumeroDeID()==iDPelicula)
            {
                encontro=i;///INDICE DE LA PELICULA ENCONTRADA
            }
        }
        if(encontro!=-1&&encontro<cantidadDeSalas)
        {
            setIDPelicula(iDPelicula);
            entradaAPelicula=vecPeliculas[encontro].getNombrePelicula();
            setEntradaAPelicula(entradaAPelicula);/// aprovechamos ya para setear el nombre de la pelicula
            numeroDeSala=vecSalas[encontro].getnumero();
            setNumeroDeSala(numeroDeSala);/// y de paso el numero de sala
            contadorDeErrores=0;
            break;
        }
        else
        {
            if(encontro==-1)cout<< "EL ID ELEGIDO NO CORRESPONDE CON UNA PELICULA EN CARTELERA"<<endl;
            if(encontro>=cantidadDeSalas)cout<< "NO HAY UNA SALA ASIGNADA PARA ESA PELICULA POR FAVOR ELIJA OTRA"<<endl;
            contadorDeErrores++;
        }
    }

    while(contadorDeErrores<3)
    {
        cout<< "INGRESE EL DNI DEL CLIENTE"<<endl;
        dNIComprador=validarEntero();/// chequear que validar ingreso de entero funcione bien

        if(dNIComprador>1000000&&dNIComprador<99999999)
        {
            setDNIComprador(dNIComprador);
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "EL DNI INGRESADO NO ES VALIDO"<<endl;
            contadorDeErrores++;
        }
    }

    if(contadorDeErrores<3)
    {
        string tipo=vecSalas[encontro].gettipo();
        if(tipo=="estandar")precio=5000;
        if(tipo=="premium")precio=7500;
        if(tipo=="confort plus")precio=10000;
        ArchivoClientes archivoCliente;
        int pos=archivoCliente.getPosicion(dNIComprador);
        if(pos!=-1)precio=precio*0.7;///descuento del 30% por ser cliente
        setPrecio(precio);
    }
    while(contadorDeErrores<3)
    {
        int cantidadDeEntradasDisponiblesEnSala;
        for(int i=0; i<FILAS; i++)
        {
            for(int j=0; j<COLUMNAS; j++)
            {
                if(!vecSalas[encontro].getButaca(i,j))
                    cantidadDeEntradasDisponiblesEnSala++;///chequeamos la cantidad de butacas disponibles para comprar
            }
        }
        cout<< "LA CANTIDAD DE ENTRADAS DISPONIBLES ES DE: "<< cantidadDeEntradasDisponiblesEnSala<<endl;
        cout<< "INGRESE LA CANTIDAD DE ENTRADAS QUE DESEA COMPRAR"<<endl;
        cantidadDeEntradas=validarEntero();///chequear si validar entero


        if(cantidadDeEntradas>0&&cantidadDeEntradas<=cantidadDeEntradasDisponiblesEnSala)
        {
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "NO ES UNA CANTIDAD VALIDA PARA COMPRAR"<<endl;
            contadorDeErrores++;
        }
    }
    int butacascompradas=0;
    int* vecFilas;
    int* vecColumnas;
    vecFilas= new int[cantidadDeEntradas];
    vecColumnas= new int[cantidadDeEntradas];
    while(contadorDeErrores<3&&butacascompradas<cantidadDeEntradas)
    {

        vecSalas[encontro].mostrarNombreTipoYButacas();
        cout<< "INGRESE LA FILA: "<<endl;
        fila=validarEntero();///chequear que funcione validar entero
        if(fila>0&&fila<=FILAS)
        {
            cout<<"INGRESE LA BUTACA: "<<endl;
            butacas=validarEntero();///chequear que funcione validar entero
            if(butacas>0&&butacas<=COLUMNAS)
            {
                if(archivoSala.ocuparButaca(numeroDeSala,fila,butacas))
                {
                    contadorDeErrores=0;
                    vecFilas[butacascompradas]=fila;
                    vecColumnas[butacascompradas]=butacas;
                    butacascompradas++;/// no hace falta el break, salimos con la compra total de entradas
                    fila--;///hacemos la resta despues de guardar las butacas compradas y filas porque en liberar tambien se resta como en ocupar
                    butacas--;
                    vecSalas[encontro].setButaca(fila,butacas,true);///(visual) esto es para que podamos ver que butacas fuimos comprando y no comprar 2 veces la misma
                }
                else
                {
                    cout<< "LA BUTACA YA ESTABA OCUPADA"<<endl;
                    contadorDeErrores++;
                }
            }
            else
            {
                cout<< "NO ES UNA BUTACA VALIDA"<<endl;
                contadorDeErrores++;
            }
        }
        else
        {
            cout<< "NO ES UNA FILA VALIDA"<<endl;
            contadorDeErrores++;
        }
        /// si llegase a haber un error en la carga de muchas entradas liberamos todas las q se fueron ocupando
        if(contadorDeErrores==3)
        {
            for(int i=0; i<butacascompradas; i++)
            {
                archivoSala.liberarButaca(numeroDeSala,vecFilas[i],vecColumnas[i]);
            }
        }
    }

    if (contadorDeErrores < 3)
    {
        vecEntradas = new Entrada[cantidadDeEntradas];
        if(!vecEntradas)
        {
            return false;
        }
        cantidadCompradas = cantidadDeEntradas;

        for (int i = 0; i < cantidadDeEntradas; i++)
        {
            vecEntradas[i].setFechaDeProyeccion(fechaDeProyeccion);
            vecEntradas[i].setIDPelicula(iDPelicula);
            vecEntradas[i].setEntradaAPelicula(entradaAPelicula);
            vecEntradas[i].setNumeroDeSala(numeroDeSala);
            vecEntradas[i].setDNIComprador(dNIComprador);
            vecEntradas[i].setCantEntradas(1);
            vecEntradas[i].setPrecio(precio);
            vecEntradas[i].setFila(vecFilas[i]);
            vecEntradas[i].setButacas(vecColumnas[i]);
        }
    }
    delete[]vecFilas;
    delete[]vecColumnas;

    delete[] vecPeliculas;
    delete[] vecSalas;
    return contadorDeErrores<3;
}
void Entrada::mostrarEntrada()
{
    cout<< "-----------------------------------------"<<endl;
    cout<< "LA FECHA DE PROYECCION ES: ";
    getFechaDeProyeccion().mostrarFecha();
    cout<< "LA PELICULA ES: "<< getEntradaAPelicula()<<endl;
    cout<< "EL DNI DEL COMPRADOR ES: "<< getDNIComprador()<<endl;
    cout<< "LA FILA ES: "<< getFila()<<endl;
    cout<< "LA BUTACA ES: "<< getButacas()<<endl;
    cout<< "EL PRECIO DE LA ENTRADA ES: $ "<< getPrecio()<<endl;
    cout<< "-----------------------------------------"<<endl;
}
int Entrada::validarEntero() /// podrias mas adelante mandar el contador por referencia
{
    int entero;

    while (true)
    {
        cin >> entero;

        if (cin.fail())
        {
            cout << "Entrada invalida. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            // Siempre limpiar el resto de la línea
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entero;
        }
    }
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
void Entrada::setDNIComprador(int dNIComprador)
{
    _dNIComprador=dNIComprador;

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
void Entrada::setPrecio(float precio)
{
    _precio=precio;
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
float Entrada::getPrecio()
{
    return _precio;
}
