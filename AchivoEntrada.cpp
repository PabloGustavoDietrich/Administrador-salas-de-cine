#include <iostream>
using namespace std;

#include "ArchivoEntrada.h"

ArchivoEntrada::ArchivoEntrada(string nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
}
/// VOLVEMOS A USAR ESTA FUNCION POR TEMAS DE VALIDACION SI QUISIERAMOS GUARDAR VECTORES
   bool ArchivoEntrada::guardarEntrada(Entrada reg){
        FILE *pFile;
        bool registro;

        pFile=fopen(_nombreArchivo.c_str(),"ab");
        if(pFile==nullptr){
            return false;
        }
        registro= fwrite(&reg,sizeof(Entrada),1,pFile);

        fclose(pFile);

        return registro;
    }
/// guardamos veector de entradas compradas
/*bool ArchivoEntrada::guardarEntradasCompradas(Entrada reg[],int cantidad)
{
    FILE *pFile;
    bool registro;

    pFile=fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr)
    {
        return false;
    }
    registro= fwrite(reg,sizeof(Entrada),cantidad,pFile);

    fclose(pFile);

    return registro;
}
*/

/// SOBREESCRITURA DEL ARCHIVO ENTRADAS ( ESTA FUNCION LA USAMOS CON LOS BACKUPS
bool ArchivoEntrada::guardarEntradas(Entrada reg[],int cantidad)
{
    FILE *pFile;
    bool registro;

    pFile=fopen(_nombreArchivo.c_str(),"wb");
    if(pFile==nullptr)
    {
        return false;
    }
    registro= fwrite(reg,sizeof(Entrada),cantidad,pFile);

    fclose(pFile);

    return registro;
}
/// OBTENEMOS LA CANTIDAD TOTAL DE ENTRADAS, MAYORMENTE LA USAMOS PARA LA CREACION DE VECTORES DINAMICOS DE ESTE TIPO DE DATO
int ArchivoEntrada::getCantidadDeEntradas()
{
    FILE *pFile;
    int cantidad;

    pFile=fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)
    {
        return 0;
    }
    fseek(pFile,0,SEEK_END);
    cantidad=ftell(pFile)/sizeof(Entrada);

    fclose(pFile);

    return cantidad;
}
/// LEEMOS TODAS LAS ENTRADAS
bool ArchivoEntrada::leerTodas(Entrada reg[],int cantidad)
{
    FILE *pFile;
    bool leyo;

    pFile=fopen(_nombreArchivo.c_str(),"rb");

    if(pFile==nullptr)
    {
        return false;
    }

    leyo=fread(reg,sizeof(Entrada),cantidad,pFile);

    fclose(pFile);

    return leyo;
}
