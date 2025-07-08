#include <iostream>
using namespace std;
#include "ArchivoPelicula.h"
ArchivoPelicula::ArchivoPelicula(string nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
}

bool ArchivoPelicula::guardarPelicula(Pelicula reg)
{
    FILE *pFile;
    bool guardo;
    pFile=fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr)
    {
        return false;
    }

    guardo=fwrite(&reg,sizeof(Pelicula),1,pFile);

    fclose(pFile);

    return guardo;
}

/// esta funcion la usamos cuando recuperamos el back up
bool ArchivoPelicula::guardarPeliculas(Pelicula reg[],int cantidad)
{
    FILE *pFile;
    bool registro;

    pFile=fopen(_nombreArchivo.c_str(),"wb");///wb sobreescribimos lo que tengamos
    if(pFile==nullptr)
    {
        return false;
    }
    registro= fwrite(reg,sizeof(Pelicula),cantidad,pFile);

    fclose(pFile);

    return registro;
}

int ArchivoPelicula::getCantidadPeliculas()
{
    int cantidad;
    FILE *pFile;
    pFile=fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)
    {
        return -1;/// chequear si es mejor retornar un 0
    }
    fseek(pFile,0,SEEK_END);
    cantidad=ftell(pFile)/sizeof(Pelicula);
    fclose(pFile);
    return cantidad;
}

int ArchivoPelicula::getCantidadPeliculasEnCartelera()
{
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr)
    {
        return 0;  // Mejor retornar 0 si no se puede abrir
    }

    Pelicula reg;
    int contador = 0;

    while (fread(&reg, sizeof(Pelicula), 1, pFile)==1)/// podemos o no igualar a 1 ya que la funcion read retorna un 1 y eso lo toma como true, y cuando no puede leer mas retorna 0
    {
        if (reg.getEstado())
        {
            contador++;
        }
    }

    fclose(pFile);
    return contador;
}

bool ArchivoPelicula::leerTodas(Pelicula reg[],int cantidad)
{
    FILE *pFile;
    bool leyo;
    pFile=fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)
    {
        return false;
    }
    leyo=fread(reg,sizeof(Pelicula),cantidad,pFile);

    fclose(pFile);

    return leyo;
}

bool ArchivoPelicula::bajaLogicaPelicula(Pelicula reg, int poscicion)
{
    FILE *pFile;
    bool escribio;
    pFile=fopen(_nombreArchivo.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

/// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, poscicion * sizeof(Pelicula), SEEK_SET);
    fread(&reg,sizeof(Pelicula),1,pFile);
/// seteamos a false para dar de baja
    if(reg.getEstado())
    {
        reg.setEstado(false);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, poscicion * sizeof(Pelicula), SEEK_SET);/// poscicion siempre adelante
        escribio=fwrite(&reg,sizeof(Pelicula),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;

}

bool ArchivoPelicula::altaLogicaPelicula(Pelicula reg, int poscicion)
{
    FILE *pFile;
    bool escribio;
    pFile=fopen(_nombreArchivo.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }

/// posicionamos el puntero y leemos los datos del registro para que queden en reg
    fseek(pFile, poscicion * sizeof(Pelicula), SEEK_SET);
    fread(&reg,sizeof(Pelicula),1,pFile);
/// seteamos a true para dar de alta
    if(!reg.getEstado())
    {
        reg.setEstado(true);
/// reposicionamos el puntero para escribir en el registro correcto
        fseek(pFile, poscicion * sizeof(Pelicula), SEEK_SET);/// poscicion siempre adelante
        escribio=fwrite(&reg,sizeof(Pelicula),1,pFile);
    }
    else
    {
        escribio=false;
    }
    fclose(pFile);

    return escribio;

}

