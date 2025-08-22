#include <iostream>
using namespace std;
#include "Constante.h"
#include "ManagerSalas.h"
#include <cstring>

void ManagerSalas::pausarYLimpiar() {
    system("pause");
    system("cls");
}
/// resuelve la opcion 1 del menu
void ManagerSalas::cargarSala()
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
    pausarYLimpiar();
}
/// Método auxiliar para leer todas las salas
Sala* ManagerSalas::leerTodasLasSalas(int &cantidad) {
    cantidad = _archivoSalas.getCantidadSalas();

    if (cantidad <= 0) {
        return nullptr;
    }

    Sala* vecSala = new Sala[cantidad];
    if (!vecSala) {
        cout << "No se pudo reservar memoria para las salas." << endl;
        cantidad = 0;
        return nullptr;
    }

    if (!_archivoSalas.leerTodas(vecSala, cantidad)) {
        delete[] vecSala;
        cantidad = 0;
        return nullptr;
    }

    return vecSala;
}
/// resuelve la opcion 2 del menu
void ManagerSalas::mostrarSalas()
{
    int cantidadDeSalas;
    Sala *vecSala=leerTodasLasSalas(cantidadDeSalas);
    if (!vecSala)return;

    for(int i=0; i <cantidadDeSalas; i++)
    {
        vecSala[i].mostrarSalaNumeroNombreYFecha();
    }
    delete[] vecSala;
    ///pausarYLimpiar();MOLESTA CUANDO LA LLAMAMOS DE OTRA FUNCIONES
}
//// resolvemos la opcion 3 del menu; y retorna la posicion esta funcion la usamos para ayudar a resolver la opcion 4 y 5 del menu
int ManagerSalas::buscarPosicionSalaPorNumero()/// TAL VEZ CON PARAMETROS POR DEFECTO PODRIA REUTILIZAR ESTA FUNCION
{
    int posicion=-1;
    int cantidadDeSalas;
    Sala *vecSala=leerTodasLasSalas(cantidadDeSalas);
    if (!vecSala)return -1;

    int numeroSala;
    cout << "------------------------------------------" << endl;
    cout<< "INGRESE EL NUMERO DE SALA QUE DESEA BUSCAR: "<<endl;
    cin>>numeroSala;

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
    cout<< "ESE NUMERO DE SALA NO EXISTE"<<endl;
    return posicion;
}
///OPCION 3 DEL MENU
void ManagerSalas::mostrarSalaPorNumero(){
    Sala registro;
    mostrarSalas();
    int pos=buscarPosicionSalaPorNumero();
    if(pos!=-1){
        _archivoSalas.leerSala(registro,pos);
        registro.mostrarSala();/// APROVECHAMOS PARA USAR EL MOSTRAR COMPLETO PORQUE ES UNA SOLA
    }
}

void ManagerSalas::mostrarSalasEstadoNYF(){
    int cantidadDeSalas;
    Sala *vecSala=leerTodasLasSalas(cantidadDeSalas);
    if (!vecSala)return;

    for(int i=0; i <cantidadDeSalas; i++)
    {
        vecSala[i].mostrarSalaNumeroEstadoYFecha();
    }
    delete[] vecSala;
}
///OPCION 4 DEL MENU DE SALAS
void ManagerSalas::bajaPorMantenimiento()
{
    mostrarSalasEstadoNYF();
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
    pausarYLimpiar();
}

///OPCION 5 DEL MENU DE SALAS
void ManagerSalas::altaPostMantenimiento()
{
    mostrarSalasEstadoNYF();
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
    pausarYLimpiar();
}

/// OPCION 6 DEL MENU DE SALAS
void ManagerSalas::mostrarSalasPorFecha()
{
    mostrarSalas();
    Fecha fechaAsignada;
    int cantidadDeSalas;
    Sala *vecSala;
    vecSala= leerTodasLasSalas(cantidadDeSalas);
    if (!vecSala)return;
    fechaAsignada.cargarFecha();
    bool banderaSala=true;
    for(int i=0; i <cantidadDeSalas; i++)
    {
        if(vecSala[i].getFechaAsignada()==fechaAsignada)
        {
            vecSala[i].mostrarSala();
            banderaSala=false;
        }
    }
    if(banderaSala)cout<<"NO HAY SALAS PARA ESA FECHA"<<endl;
    delete[] vecSala;
    pausarYLimpiar();
}

