#include <iostream>
using namespace std;

#include "ArchivoGenero.h"
ArchivoGenero::ArchivoGenero(string nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
}

bool ArchivoGenero::guardarGenero(Genero reg)
{
    FILE *pFile;
    bool guardo;
    pFile=fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr)
    {
        return false;
    }

    guardo=fwrite(&reg,sizeof(Genero),1,pFile);

    fclose(pFile);

    return guardo;
}

int ArchivoGenero::getCantidadGeneros()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)
    {
        return -1;/// chequear si es mejor retornar un 0
    }
    fseek(pFile,0,SEEK_END);
    cantidad=ftell(pFile)/sizeof(Genero);
    fclose(pFile);
    return cantidad;
}


bool ArchivoGenero::leerTodas(Genero reg[],int cantidad)
{
    FILE *pFile;
    bool leyo;
    pFile=fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)
    {
        return false;
    }
    leyo=fread(reg,sizeof(Genero),cantidad,pFile);

    fclose(pFile);

    return leyo;
}

bool ArchivoGenero::bajaLogicaGenero(Genero reg, int poscicion)
{
    FILE *pFile;
    bool escribio;
    pFile=fopen(_nombreArchivo.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

/// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, poscicion * sizeof(Genero), SEEK_SET);
    fread(&reg,sizeof(Genero),1,pFile);
/// seteamos a false para dar de baja
    if(reg.getEstado())
    {
        reg.setEstado(false);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, poscicion * sizeof(Genero), SEEK_SET);/// poscicion siempre adelante
        escribio=fwrite(&reg,sizeof(Genero),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;

}

bool ArchivoGenero::altaLogicaGenero(Genero reg, int poscicion)
{
    FILE *pFile;
    bool escribio;
    pFile=fopen(_nombreArchivo.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

/// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, poscicion * sizeof(Genero), SEEK_SET);
    fread(&reg,sizeof(Genero),1,pFile);
/// seteamos a true para dar de alta
    if(!reg.getEstado())
    {
        reg.setEstado(true);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, poscicion * sizeof(Genero), SEEK_SET);/// poscicion siempre adelante
        escribio=fwrite(&reg,sizeof(Genero),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;

}

