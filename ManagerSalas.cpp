#include <iostream>
using namespace std;
#include "Constante.h"
#include "ManagerSalas.h"
#include <cstring>

/// resuelve la opcion 1 del menu
void ManagerSalas::CargarSala()
{
    bool banderaDeCarga=true;
    bool banderaDeError=false;
    int numeroSala;
    string nombreSala;
    int tipo;
    int estado;
    Sala reg;

/// COMO SOLO DAMOS BAJAS DE MANTENIMIENTO LOGICAS Y NO ELIMINAMOS NADA
    numeroSala=_archivoSalas.getCantidadSalas()+1;/// se retorna 0 si no puede leer el archivo
    reg.setnumero(numeroSala);



    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "Ingrese el nombre de la Sala: "<<endl;
        cin.ignore();
        getline(cin,nombreSala);/// validar igual que hoy
        banderaDeError=reg.setnombre(nombreSala);
        if(!banderaDeError)
        {
            cout<<"Error con la carga del nombre de la sala, (precione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
        }
    }
    banderaDeError=false;/// seteamos la bandera a false para la siguiente carga de datos



    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "Ingrese el tipo de Sala(1:Estandar,2:Premium,3:Confort Plus): "<<endl;
        cin>> tipo;
        banderaDeError=reg.settipo(tipo);
        if(!banderaDeError)
        {
            cout<<"Error con la carga del tipo de la sala, (precione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
        }
    }
    banderaDeError=false;/// seteamos la bandera a false para la siguiente carga de datos



    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "Ingrese estado de la sala : (si no esta diponible 0, si esta disponible 1)"<<endl;
        cin>> estado;

        if(estado==1||estado==0)
        {
            reg.setEstado(estado);
            banderaDeError=true;
        }
        else
        {
            cout<<"Error con la carga del estado de la sala, (precione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
        }
    }
    banderaDeError=false;/// seteamos la bandera a false para la siguiente carga de datos

    ///por defecto cuando creamos una sala todas las butacas las seteamos a false
    reg.setButacas();

    //reg=Sala(numeroSala,nombreSala,tipo,estado);

    cout <<"_________________________" << endl;
    cout << endl;

    if(banderaDeCarga&&!banderaDeError)
    {
        if(_archivoSalas.guardarSala(reg))
        {
            cout<< "LA SALA SE GUARDO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<< "ERROR AL GUARDAR LA SALA"<<endl;
        }
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
            MostrarSala(vecSala[i]);
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
void ManagerSalas::MostrarSala(Sala reg)
{
    cout<< "SALA #: "<<reg.getnumero()<<endl;
    cout<< "EL NOMBRE DE LA SALA ES: "<< reg.getnombre()<<endl;
    switch(reg.gettipo())
    {
    case 1:
        cout<< "LA SALA ES ESTANDAR"<<endl;
        break;
    case 2:
        cout<< "LA SALA ES PREMIUM"<<endl;
        break;
    case 3:
        cout<< "LA SALA ES COMFORT PLUS"<<endl;
    }
    if(reg.getEstadoSala())
    {
        cout<< "LA SALA ESTA ACTIVA"<<endl;
    }
    else
    {
        cout<< "LA SALA ESTA EN MANTENIMIENTO"<<endl;
    }
    for(int i=0; i<FILAS; i++)
    {
        cout<<"FILA: "<<i+1<<" :";
        for(int j=0; j<COLUMNAS; j++)
        {

            if(!reg.getButaca(i,j))
            {
                cout<< "L ";
            }
            else
            {
                cout<< "O ";
            }
        }
        cout<<endl;
    }

    cout<< "---------------------------"<<endl;

}


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
                MostrarSala(vecSala[i]);
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

    MostrarSala(registro);

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
