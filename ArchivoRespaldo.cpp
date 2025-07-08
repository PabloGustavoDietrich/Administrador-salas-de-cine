#include <iostream>
using namespace std;

#include "ArchivoRespaldo.h"

bool ArchivoRespaldo::respaldoEntradas(Entrada reg[],int cantidad)
{
    FILE *pFile;
    bool respaldo;
    pFile=fopen("respaldoEntradas.dat","wb");/// el nombre esta aca

    if(pFile==nullptr)
    {
        return false;
    }
    respaldo=fwrite(reg,sizeof(Entrada),cantidad,pFile);

    fclose(pFile);

    return respaldo;
}

int ArchivoRespaldo::getCantidadDeEntradasDeRespaldo()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen("respaldoEntradas.dat","rb");
    if(pFile==nullptr)
    {
        return -1;/// chequear si es mejor retornar un 0
    }
    fseek(pFile,0,SEEK_END);

    cantidad=ftell(pFile)/sizeof(Entrada);

    fclose(pFile);

    return cantidad;
}

bool ArchivoRespaldo::recuperarEntradas(Entrada reg[],int cantidad)
{
    FILE *pFile;
    bool respaldo;
    pFile=fopen("respaldoEntradas.dat","rb");

    if(pFile==nullptr)
    {
        return false;
    }
    respaldo=fread(reg,sizeof(Entrada),cantidad,pFile);

    fclose(pFile);

    return respaldo;
}

bool ArchivoRespaldo::respaldoPeliculas(Pelicula reg[],int cantidad)
{
    FILE *pFile;
    bool respaldo;
    pFile=fopen("respaldoPeliculas.dat","wb");

    if(pFile==nullptr)
    {
        return false;
    }
    respaldo=fwrite(reg,sizeof(Pelicula),cantidad,pFile);

    fclose(pFile);

    return respaldo;
}
int ArchivoRespaldo::getCantidadDePeliculasDeRespaldo()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen("respaldoPeliculas.dat","rb");
    if(pFile==nullptr)
    {
        return -1;/// chequear si es mejor retornar un 0
    }
    fseek(pFile,0,SEEK_END);

    cantidad=ftell(pFile)/sizeof(Pelicula);

    fclose(pFile);

    return cantidad;
}
bool ArchivoRespaldo::recuperarPeliculas(Pelicula reg[],int cantidad)
{
    FILE *pFile;
    bool respaldo;
    pFile=fopen("respaldoPeliculas.dat","rb");

    if(pFile==nullptr)
    {
        return false;
    }
    respaldo=fread(reg,sizeof(Pelicula),cantidad,pFile);

    fclose(pFile);

    return respaldo;
}


bool ArchivoRespaldo::respaldoSalas(Sala reg[],int cantidad)
{
    FILE *pFile;
    bool respaldo;
    pFile=fopen("respaldoSalas.dat","wb");

    if(pFile==nullptr)
    {
        return false;
    }
    respaldo=fwrite(reg,sizeof(Sala),cantidad,pFile);

    fclose(pFile);

    return respaldo;
}
int ArchivoRespaldo::getCantidadDeSalasDeRespaldo()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen("respaldoSalas.dat","rb");
    if(pFile==nullptr)
    {
        return -1;/// chequear si es mejor retornar un 0
    }
    fseek(pFile,0,SEEK_END);

    cantidad=ftell(pFile)/sizeof(Sala);

    fclose(pFile);

    return cantidad;
}
bool ArchivoRespaldo::recuperarSalas(Sala reg[],int cantidad)
{
    FILE *pFile;
    bool respaldo;
    pFile=fopen("respaldoSalas.dat","rb");

    if(pFile==nullptr)
    {
        return false;
    }
    respaldo=fread(reg,sizeof(Sala),cantidad,pFile);

    fclose(pFile);

    return respaldo;
}


