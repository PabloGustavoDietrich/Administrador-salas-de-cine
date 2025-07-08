#include <iostream>
#include <string>
#include "ArchivoSala.h"
using namespace std;

ArchivoSala::ArchivoSala(string nombreArchivoSala)
{
    _nombreArchivoSala=nombreArchivoSala;
}
bool ArchivoSala::guardarSala(Sala reg)
{
    FILE *pFile;
    bool guardo;
    pFile=fopen(_nombreArchivoSala.c_str(),"ab");
    if(pFile==nullptr)
    {
        return false;
    }

    guardo=fwrite(&reg,sizeof(Sala),1,pFile);

    fclose(pFile);

    return guardo;
}

bool ArchivoSala::guardarSalas(Sala reg[],int cantidad)
{
    FILE *pFile;
    bool registro;

    pFile=fopen(_nombreArchivoSala.c_str(),"wb");
    if(pFile==nullptr)
    {
        return false;
    }
    registro= fwrite(reg,sizeof(Sala),cantidad,pFile);

    fclose(pFile);

    return registro;
}

int ArchivoSala::getCantidadSalas()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen(_nombreArchivoSala.c_str(),"rb");
    if(pFile==nullptr)
    {
        return 0;
    }
    fseek(pFile,0,SEEK_END);
    cantidad=ftell(pFile)/sizeof(Sala);
    fclose(pFile);
    return cantidad;
}

bool ArchivoSala::leerTodas(Sala reg[],int cantidad)
{
    FILE *pFile;
    bool leyo;
    pFile=fopen(_nombreArchivoSala.c_str(),"rb");
    if(pFile==nullptr)
    {
        return false;
    }
    leyo=fread(reg,sizeof(Sala),cantidad,pFile);

    fclose(pFile);

    return leyo;
}

bool ArchivoSala::leerSala(Sala &reg,int posicion)///mandamos la referencia
{
    FILE *pFile;
    bool leyo;
    pFile=fopen(_nombreArchivoSala.c_str(),"rb");
    if(pFile==nullptr)
    {
        return false;
    }
    fseek(pFile, posicion * sizeof(Sala), SEEK_SET);
    leyo=fread(&reg,sizeof(Sala),1,pFile);

    fclose(pFile);

    return leyo;
}

bool ArchivoSala::bajaLogicaSala(Sala reg, int posicion)
{
    FILE *pFile;
    bool escribio;
    pFile=fopen(_nombreArchivoSala.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }
/// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, posicion * sizeof(Sala), SEEK_SET);
    fread(&reg,sizeof(Sala),1,pFile);
/// seteamos a false para dar de baja
    if(reg.getEstadoSala())
    {
        reg.setEstado(false);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, posicion * sizeof(Sala), SEEK_SET);/// pocicion siempre adelante
        escribio=fwrite(&reg,sizeof(Sala),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;

}

bool ArchivoSala::altaLogicaSala(Sala reg, int posicion)
{
    FILE *pFile;
    bool escribio;
    pFile=fopen(_nombreArchivoSala.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

/// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, posicion * sizeof(Sala), SEEK_SET);
    fread(&reg,sizeof(Sala),1,pFile);
    if (!reg.getEstadoSala())
    {
/// seteamos a true para dar de alta
        reg.setEstado(true);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, posicion * sizeof(Sala), SEEK_SET);/// pocicion siempre adelante
        escribio=fwrite(&reg,sizeof(Sala),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;

}

/// ESTA FUNCION MODIFICA LA BUTACA ELEGIDA POR EL COMPRADOR DE LA ENTRADA
bool ArchivoSala::ocuparButaca(Sala reg,int posicion,int fila,int butaca)
{
    FILE *pFile;
    bool escribio;
/// CORREGIMOS FILA Y BUTACA PARA QUE SE ADAPTE A LAS POSICIONES DE LA MATRIZ
    fila--;
    butaca--;

    pFile=fopen(_nombreArchivoSala.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

    /// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, posicion * sizeof(Sala), SEEK_SET);
    fread(&reg,sizeof(Sala),1,pFile);
    if (!reg.getButaca(fila,butaca))
    {
/// seteamos a true para ocupar butaca
        reg.setButaca(fila,butaca,true);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, posicion * sizeof(Sala), SEEK_SET);
        escribio=fwrite(&reg,sizeof(Sala),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;
}
