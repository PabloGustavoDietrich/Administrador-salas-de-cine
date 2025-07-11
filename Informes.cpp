#include <iostream>
using namespace std;
#include "Informes.h"
#include "Entrada.h"
#include "Pelicula.h"
#include "Sala.h"
#include <cstring>

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

    string listaDeGeneros[]= {"accion","ciencia ficcion","terror","belico","fantasia","comedia","romantico","western","thriller"};
    const int TAMANIO=9;
    int vecContadores[TAMANIO]= {0};

    cantidadEntradas=_archivoEntrada.getCantidadDeEntradas();
    cantidadPeliculas=_archivoPelicula.getCantidadPeliculas();
    if(cantidadEntradas>0&&cantidadPeliculas>0)
    {
        vecEntradas= new Entrada[cantidadEntradas];
        vecPeliculas=new Pelicula[cantidadPeliculas];

        _archivoEntrada.leerTodas(vecEntradas,cantidadEntradas);
        _archivoPelicula.leerTodas(vecPeliculas,cantidadPeliculas);
/// PROCESO DE CUENTAS
        for(int i=0; i<cantidadEntradas; i++)
        {
            for(int j=0; j<cantidadPeliculas; j++)
            {
                /// PREGUNTAMOS SI EL ID DE LA PELICULA ES IGUAL AL DE LA ENTRADA COMPRADA
                if (vecPeliculas[j].getNumeroDeID()==vecEntradas[i].getIDPelicula())
                {
                    for(int k=0; k<TAMANIO; k++)
                    {
                        if(vecPeliculas[j].getGeneroPelicula()==listaDeGeneros[k])
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
            cout<<"Del Genero: "<<listaDeGeneros[i]<< ", se vendieron: "<<vecContadores[i]<< ", entradas."<<endl;
            cout<<"==========="<<endl;
        }

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

        int vecContadores[cantidadPeliculas]= {0};
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
