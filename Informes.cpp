#include <iostream>
using namespace std;
#include "Informes.h"
#include "Entrada.h"
#include "Pelicula.h"
#include "Sala.h"
#include "Genero.h"
#include <cstring>
#include <iomanip>

void Informes::mostrarCantidadDeEntradasVendidas()
{
    cout<<"LA CANTIDAD TOTAL DE ENTRADAS VENDIDAS ES: "<<_archivoEntrada.getCantidadDeEntradas()<<endl;
    system("pause");
    system("cls");
}

void Informes::mostrarCantidadEntradasVendidasPorgenero()
{
    int cantidadEntradas;
    Entrada *vecEntradas;
    int cantidadPeliculas;
    Pelicula *vecPeliculas;
    int cantidadGeneros;
    Genero *vecGenero;
    int *vecContadores;

    cantidadGeneros=_archivoGenero.getCantidadGeneros();
    cantidadEntradas=_archivoEntrada.getCantidadDeEntradas();
    cantidadPeliculas=_archivoPelicula.getCantidadPeliculas();

    if(cantidadEntradas>0&&cantidadPeliculas>0&&cantidadGeneros>0)
    {
        vecEntradas=new Entrada[cantidadEntradas];
        vecPeliculas=new Pelicula[cantidadPeliculas];
        vecGenero=new Genero[cantidadGeneros];
        vecContadores=new int[cantidadGeneros]{};

        _archivoEntrada.leerTodas(vecEntradas,cantidadEntradas);
        _archivoPelicula.leerTodas(vecPeliculas,cantidadPeliculas);
        _archivoGenero.leerTodas(vecGenero,cantidadGeneros);
/// PROCESO DE CUENTAS
        for(int i=0; i<cantidadEntradas; i++)
        {
            for(int j=0; j<cantidadPeliculas; j++)
            {
                /// PREGUNTAMOS SI EL ID DE LA PELICULA ES IGUAL AL DE LA ENTRADA COMPRADA
                if (vecPeliculas[j].getNumeroDeID()==vecEntradas[i].getIDPelicula())
                {
                    for(int k=0; k<cantidadGeneros; k++)
                    {
                        if(vecPeliculas[j].getGeneroPelicula()==vecGenero[k].getNombreGenero())
                        {
                            vecContadores[k]++;
                        }
                    }
                }
            }
        }
/// PROCESO DE MUESTRA
        for(int i=0; i<cantidadGeneros; i++)
        {
            cout<<"Del Genero: "<<vecGenero[i].getNombreGenero()<< ", se vendieron: "<<vecContadores[i]<< ", entradas."<<endl;
            cout<<"==========="<<endl;
        }
        delete[] vecGenero;
        delete[] vecContadores;
        delete[] vecEntradas;
        delete[] vecPeliculas;
    }
    else
    {
        cout<<"FALTAN DATOS PARA REALIZAR EL INFORME"<<endl;
    }
    system("pause");
    system("cls");
}

void Informes::mostrarCantidadDeEntradasVendidasPorTitulo()
{
    int cantidadEntradas;
    Entrada *vecEntradas;
    int cantidadPeliculas;
    Pelicula *vecPeliculas;
    string *listaDeTitulos;


    cantidadEntradas=_archivoEntrada.getCantidadDeEntradas();
    cantidadPeliculas=_archivoPelicula.getCantidadPeliculas();
    if(cantidadEntradas>0&&cantidadPeliculas>0)
    {
        vecEntradas= new Entrada[cantidadEntradas];
        vecPeliculas=new Pelicula[cantidadPeliculas];
        listaDeTitulos= new string[cantidadPeliculas];

        _archivoEntrada.leerTodas(vecEntradas,cantidadEntradas);
        _archivoPelicula.leerTodas(vecPeliculas,cantidadPeliculas);

        for(int i=0; i<cantidadPeliculas; i++)
        {
            listaDeTitulos[i]=vecPeliculas[i].getNombrePelicula();
        }

        int *vecContadores;
        vecContadores=new int [cantidadPeliculas]{};
/// PROCESO DE CUENTAS
        for(int i=0; i<cantidadEntradas; i++)
        {
            for(int j=0; j<cantidadPeliculas; j++)
            {
                /// PREGUNTAMOS SI EL ID DE LA PELICULA ES IGUAL AL DE LA ENTRADA COMPRADA
                if (vecPeliculas[j].getNumeroDeID()==vecEntradas[i].getIDPelicula())
                {
                    vecContadores[vecPeliculas[j].getNumeroDeID()-1]++;

                }
            }
        }
/// PROCESO DE MUESTRA
        for(int i=0; i<cantidadPeliculas; i++)
        {
            cout<<"Del Titulo: "<<listaDeTitulos[i]<< ", se vendieron: "<<vecContadores[i]<< ", entradas."<<endl;
            cout<<"==========="<<endl;
        }

        delete[] vecEntradas;
        delete[] vecPeliculas;
        delete[] listaDeTitulos;
        delete[] vecContadores;
    }
    else
    {
        cout<<"FALTAN DATOS PARA REALIZAR EL INFORME"<<endl;
    }
    system("pause");
    system("cls");
}

void Informes::mostrarCantidadDeEntradasVendidasPorTipoDeSala()
{
    int cantidadEntradas;
    Entrada *vecEntradas;
    int cantidadSalas;
    Sala *vecSalas;

    string listaDeTipoDeSala[]= {"estandar","premium","confort plus"};
    const int TAMANIO=3;
    int vecContadores[TAMANIO]= {0};

    cantidadEntradas=_archivoEntrada.getCantidadDeEntradas();
    cantidadSalas=_archivoSala.getCantidadSalas();
    if(cantidadEntradas>0&&cantidadSalas>0)
    {
        vecEntradas= new Entrada[cantidadEntradas];
        vecSalas=new Sala[cantidadSalas];

        _archivoEntrada.leerTodas(vecEntradas,cantidadEntradas);
        _archivoSala.leerTodas(vecSalas,cantidadSalas);

        /// PROCESO DE CUENTAS
        for(int i=0; i<cantidadEntradas; i++)
        {
            for(int j=0; j<cantidadSalas; j++)
            {
                /// PREGUNTAMOS SI EL NUMERO DE LA SALA COINCIDE
                if (vecSalas[j].getnumero()==vecEntradas[i].getNumeroDeSala())
                {
                    for(int k=0; k<TAMANIO; k++)
                    {
                        if(vecSalas[j].gettipo()==listaDeTipoDeSala[k])
                        {
                            vecContadores[k]++;

                        }
                    }
                }
            }
        }

        /// PROCESO DE MUESTRA
        for(int i=0; i<TAMANIO; i++)
        {
            cout<<"Del tipo de sala: "<<listaDeTipoDeSala[i]<< ", se vendieron: "<<vecContadores[i]<< ", entradas."<<endl;
            cout<<"================="<<endl;
        }

        delete[] vecEntradas;
        delete[] vecSalas;
    }
    else
    {
        cout<<"FALTAN DATOS PARA REALIZAR EL INFORME"<<endl;
    }
    system("pause");
    system("cls");
}
void Informes::mostrarRecaudacion(){
 int cantidadEntradas=_archivoEntrada.getCantidadDeEntradas();
 Entrada *vecEntradas;
 vecEntradas=new Entrada[cantidadEntradas];
 if(vecEntradas==nullptr){
    return;
 }
string vecMeses[12]={"enero", "febrero", "marzo","abril", "mayo", "junio", "julio", "agosto", "septiembre","octubre","noviembre","diciembre"};

_archivoEntrada.leerTodas(vecEntradas, cantidadEntradas);

float recMensual[12]={};
float recTotal=0;
for(int i=0;i<cantidadEntradas;i++){
    recMensual[vecEntradas[i].getFechaDeProyeccion().getMes()-1]+=vecEntradas[i].getPrecio();
}
for(int i=0;i<12;i++){
    recTotal+=recMensual[i];
}
for(int i=0;i<12;i++){

    cout<<"En el mes "<<vecMeses[i]<< " se recaudo: $ "<<recMensual[i]<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<endl;
}
cout << fixed << setprecision(2);
cout<<"*****************************************"<<endl;
cout<<"La recaudacion total fue: $ "<<recTotal<<endl;
cout<<"*****************************************"<<endl;
delete[] vecEntradas;
system("pause");
system("cls");

}
