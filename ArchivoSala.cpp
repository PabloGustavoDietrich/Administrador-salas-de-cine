#include <iostream>
#include <string>
#include "ArchivoSala.h"
#include "Sala.h"
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
bool ArchivoSala::ocuparButaca(int numeroSala,int fila,int butaca)
{
    FILE *pFile;
    bool escribio=false;
    Sala registro;
/// CORREGIMOS FILA Y BUTACA PARA QUE SE ADAPTE A LAS POSICIONES DE LA MATRIZ
    fila--;
    butaca--;

    pFile=fopen(_nombreArchivoSala.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }
    int pos=0;
    while(fread(&registro,sizeof(Sala),1,pFile))
    {
        if(registro.getnumero()==numeroSala)
        {
            if (!registro.getButaca(fila,butaca))
            {
/// seteamos a true para ocupar butaca
                registro.setButaca(fila,butaca,true);
/// reposicionamos el puntero para escribir en el registro correcto
                fseek(pFile, pos * sizeof(Sala), SEEK_SET);
                escribio=fwrite(&registro,sizeof(Sala),1,pFile);
                break;
            }
        }
        pos++;
    }

    fclose(pFile);

    return escribio;
}

bool ArchivoSala::liberarButaca(int numeroSala,int fila,int butaca)
{
    FILE *pFile;
    bool escribio=false;
    Sala registro;
/// CORREGIMOS FILA Y BUTACA PARA QUE SE ADAPTE A LAS POSICIONES DE LA MATRIZ
    fila--;
    butaca--;

    pFile=fopen(_nombreArchivoSala.c_str(),"rb+");
    if(pFile==nullptr)
    {
        return false;
    }
    int pos=0;
    while(fread(&registro,sizeof(Sala),1,pFile))
    {
        if(registro.getnumero()==numeroSala)
        {
            if (registro.getButaca(fila,butaca))
            {
/// seteamos a false para liberar butaca
                registro.setButaca(fila,butaca,false);
/// reposicionamos el puntero para escribir en el registro correcto
                fseek(pFile, pos * sizeof(Sala), SEEK_SET);
                escribio=fwrite(&registro,sizeof(Sala),1,pFile);
                break;
            }
        }
        pos++;
    }

    fclose(pFile);

    return escribio;
}

int ArchivoSala::getCantidadSalasPorFecha(Fecha fechaDeProyeccion)
{
    int cantidad=0;
    Sala registro;
    FILE *pFile;
    pFile=fopen(_nombreArchivoSala.c_str(),"rb");
    if(pFile==nullptr)
    {
        return 0;
    }
    while(fread(&registro,sizeof(Sala),1,pFile))
    {
        if(registro.getFechaAsignada()==fechaDeProyeccion&& registro.getEstadoSala())
        {
            cantidad++;
        }
    }
    fclose(pFile);
    return cantidad;
}

void ArchivoSala::leerSalasDisponiblesPorFecha(Sala reg[],Fecha fechaAsignada)
{
    FILE *pFile = fopen(_nombreArchivoSala.c_str(), "rb");
    if (pFile == nullptr)
    {
        return;  // Mejor retornar 0 si no se puede abrir
    }
    Sala registro;
    int contador=0;
    while (fread(&registro, sizeof(Sala), 1, pFile)==1)/// podemos o no igualar a 1 ya que la funcion read retorna un 1 y eso lo toma como true, y cuando no puede leer mas retorna 0
    {
        if (registro.getEstadoSala()&&registro.getFechaAsignada()==fechaAsignada)
        {
            reg[contador]=registro;
            contador++;
        }
    }

    fclose(pFile);
}
