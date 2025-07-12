#include <iostream>
using namespace std;
#include "Constante.h"
#include "ManagerSalas.h"
#include <cstring>

/// resuelve la opcion 1 del menu
void ManagerSalas::CargarSala()
{
    Sala registro;
    if(registro.cargarSala())
    {
        if(_archivoSalas.guardarSala(registro))
        {
            cout<< "LA SALA SE GUARDO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<< "ERROR AL GUARDAR LA SALA"<<endl;
        }
    }
    else
    {
        cout<< "NO SE PUDO CARGAR LA SALA CORRECTAMENTE"<<endl;
    }

    system("pause");
    system("cls");

}
/// resuelve la opcion 2 del menu
void ManagerSalas::MostrarSalas()
{
    int cantidadDeSalas;
    Sala *vecSala;
    cantidadDeSalas=_archivoSalas.getCantidadSalas();
    vecSala=new Sala[cantidadDeSalas];
    if (vecSala == nullptr)
    {
        cout << "No se pudo reservar memoria para las salas." << endl;
        return;
    }/// se valido la optencion de memoria
    if(_archivoSalas.leerTodas(vecSala,cantidadDeSalas))
    {
        for(int i=0; i <cantidadDeSalas; i++)
        {
            vecSala[i].mostrarSala();
        }
    }
    else
    {
        cout << "NO SE PUDIERON LEER LAS SALAS" << endl;
        system("pause");
        system("cls");
    }
    delete[] vecSala;
}

/// ayuda en la resolucion de la opcion 2 del menu y a la funcion que muestra la sala que se quiere comprar la entrada

//// resolvemos la opcion 3 del menu; y retorna la posicion esta funcion la usamos para ayudar a resolver la opcion 4 y 5 del menu
int ManagerSalas::buscarPosicionSalaPorNumero(int numeroSala)/// TAL VEZ CON PARAMETROS POR DEFECTO PODRIA REUTILIZAR ESTA FUNCION
{

    int posicion=-1;
    int cantidadDeSalas;
    Sala *vecSala;

    if(numeroSala==0)
    {
        cout<< "INGRESE EL NUMERO DE SALA QUE DESEA BUSCAR: "<<endl;
        cin>>numeroSala;
    }
    cantidadDeSalas=_archivoSalas.getCantidadSalas();
    vecSala=new Sala[cantidadDeSalas];
    if (vecSala == nullptr)
    {
        cout << "No se pudo reservar memoria para las salas." << endl;
        return -1;
    }/// se valido la optencion de memoria
    _archivoSalas.leerTodas(vecSala,cantidadDeSalas);

    for(int i=0; i<cantidadDeSalas; i++)
    {
        if(numeroSala==vecSala[i].getnumero())
        {
            delete[] vecSala;
            posicion=i;
            return posicion;
        }
    }
    delete[] vecSala;
    return posicion;
}

///OPCION 4 DEL MENU DE SALAS
void ManagerSalas::bajaPorMantenimiento()
{
    int posicion;
    Sala registro;
    posicion=buscarPosicionSalaPorNumero();
    if(posicion== -1) /// si el valor de posicion fuese -1 quiere decir que no se encontro una posicion para la sala;
    {
        cout<< "LA SALA NO EXISTE"<<endl;
    }
    else if(_archivoSalas.bajaLogicaSala(registro, posicion))
    {
        cout<< "SALA DADA DE BAJA CON EXITO"<<endl;
    }
    else
    {
        cout<< "LA SALA YA ESTABA EN MANTENIMIENTO"<<endl;
    }
    system("pause");
    system("cls");
}

///OPCION 5 DEL MENU DE SALAS
void ManagerSalas::altaPostMantenimiento()
{
    int posicion;
    Sala registro;
    posicion=buscarPosicionSalaPorNumero();
    if(posicion== -1) /// si el valor de posicion fuese -1 quiere decir que no se encontro una posicion para la sala;
    {
        cout<< "LA SALA NO EXISTE"<<endl;
    }
    else if(_archivoSalas.altaLogicaSala(registro, posicion))
    {
        cout<< "SALA DADA DE ALTA CON EXITO"<<endl;
    }
    else
    {
        cout<< "LA SALA YA ESTABA EN FUNCIONAMIENTO"<<endl;
    }
    system("pause");
    system("cls");
}

/// OPCION 6 DEL MENU DE SALAS
void ManagerSalas::MostrarSalasActivas()
{

    int cantidadDeSalas;
    Sala *vecSala;
    cantidadDeSalas=_archivoSalas.getCantidadSalas();
    vecSala=new Sala[cantidadDeSalas];
    if (vecSala == nullptr)
    {
        cout << "No se pudo reservar memoria para las salas." << endl;
        return;
    }/// se valido la optencion de memoria
    if(_archivoSalas.leerTodas(vecSala,cantidadDeSalas))
    {
        for(int i=0; i <cantidadDeSalas; i++)
        {
            if(vecSala[i].getEstadoSala())
            {
                vecSala[i].mostrarSala();
            }
        }
    }
    else
    {
        cout << "No se pudieron leer las salas" << endl;
    }

    delete[] vecSala;
    system("pause");
    system("cls");
}

/// ESTA FUNCIONA LA USAMOS EN LA COMPRA DE ENTRADAS
void ManagerSalas::mostrarSalaPorNumero(int numeroSala)/// podria enviar un false si la sala no la encuentra de ser necesario
{
    int posicion;
    Sala registro;
    posicion=buscarPosicionSalaPorNumero(numeroSala);

    _archivoSalas.leerSala(registro,posicion);/// mandamos la referencia

    registro.mostrarSala();

}
/// ESTA FUNCIONA LA USAMOS EN LA COMPRA DE ENTRADAS
void ManagerSalas::mostrarSalaConNumero(int numeroSala,int &contadorDeSalasFueraDeServicio)/// podria enviar un false si la sala no la encuentra de ser necesario
{
    int posicion;
    Sala registro;
    posicion=buscarPosicionSalaPorNumero(numeroSala);

    _archivoSalas.leerSala(registro,posicion);/// mandamos la referencia

    cout<< "SALA #: "<<registro.getnumero()<<endl;
    if(registro.getEstadoSala())
    {
        cout<< "LA SALA ESTA ACTIVA"<<endl;
    }
    else
    {
        cout<< "LA SALA ESTA EN MANTENIMIENTO"<<endl;
        contadorDeSalasFueraDeServicio++;
    }

}
/// ESTA FUNCIONA LA USAMOS EN LA COMPRA DE ENTRADAS
bool ManagerSalas::validaEstadoSala(int numeroSala)/// podria enviar un false si la sala no la encuentra de ser necesario
{
    int posicion;
    Sala registro;
    posicion=buscarPosicionSalaPorNumero(numeroSala);

    _archivoSalas.leerSala(registro,posicion);/// mandamos la referencia
    return registro.getEstadoSala();/// esta funcion retorna un booleano
}

/// ESTA FUNCIONA LA USAMOS EN LA COMPRA DE ENTRADAS
bool ManagerSalas::comprarButaca(int numeroSala,int fila,int butaca)  ///cambie el tipo de funcion de void a bool para poder utilizar un while si la butaca está ocupada.
{
    Sala reg;
    int posicion;
    posicion=buscarPosicionSalaPorNumero(numeroSala);

    if(_archivoSalas.ocuparButaca(reg,posicion,fila,butaca))
    {
        cout<< "BUTACA COMPRADA CON EXITO"<<endl;
        return true;
    }
    else
    {
        cout<< "ERROR CON LA BUTACA SELECCIONADA"<<endl;
        return false;
    }
}

int ManagerSalas::cantidadDeSalas()
{
    int cantidadDeSalas;
    cantidadDeSalas=_archivoSalas.getCantidadSalas();
    return cantidadDeSalas;
}
