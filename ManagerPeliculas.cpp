#include <iostream>
using namespace std;
#include "ManagerPeliculas.h"
#include <cstring>

void ManagerPeliculas::cargarPelicula()
{
    bool banderaDeCarga=true;
    bool banderaDeError=false;
    bool banderaDeError2=true;
    int cantidadDePeliculas;
    int peliculaID;
    string nombrePelicula;
    string nombreDelDirector;
    string apellidoDelDirector;
    string generoPelicula;
    string clasificacionPelicula;
    Fecha fechaDeEstreno;
    Pelicula registro;

    /// PODEMOS ASIGNAR ID DE ESTA MANERA YA QUE NO ELIMINAMOS PELICULAS SINO SOLO DAMOS BAJAS LOGICAS
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();///nos guardamos el valor de la cantidad de pwliculas que hay
   /* if(cantidadDePeliculas<0) ///si no hay peliculas nos llega un -1
    {
        peliculaID=1;
        registro.setNumeroID(peliculaID);
    }
    else
    {
        peliculaID=cantidadDePeliculas+1;
        registro.setNumeroID(peliculaID);
    }*/

    while(banderaDeCarga&&!banderaDeError&&banderaDeError2)
    {
        cout<< "Ingrese el nombre de la Pelicula: "<<endl;
        cin.ignore();///sin el ignore nos manda directamente al mensaje de error
        getline(cin,nombrePelicula);
        banderaDeError2=verificarSiExiste(nombrePelicula);
        banderaDeError=registro.setNombrePelicula(nombrePelicula);
        if(banderaDeError2)
        {
            cout<<"Error con la carga del nombre, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }
    }
    banderaDeError=false;/// seteamos la bandera a false para la siguiente carga de datos

    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "Ingrese nombre del Director: "<<endl;
        getline(cin,nombreDelDirector);
        banderaDeError=registro.setNombreDelDirector(nombreDelDirector);
        if(!banderaDeError)
        {
            cout<<"Error con la carga del nombre, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();///en este caso en importante dejar el ignore aca distinto de la carga anterior
        }
    }
    banderaDeError=false;

    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "ingrese el apellido del director: "<<endl;
        getline(cin,apellidoDelDirector);
        banderaDeError=registro.setApellidoDelDirector(apellidoDelDirector);
        if(!banderaDeError)
        {
            cout<<"Error con la carga del apellido, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }
    }
    banderaDeError=false;


    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "ingrese el genero de la pelicula: "<<endl;
        getline(cin,generoPelicula);
        banderaDeError=registro.setGeneroPelicula(generoPelicula);
        if(!banderaDeError)
        {
            cout<<"Error con la carga del genero de la pelicula, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }
    }
    banderaDeError=false;

    while(banderaDeCarga&&!banderaDeError)
    {
        cout<< "ingrese la clasificacion de la pelicula: (ATP, mayores de 14 y mayores de 18)"<<endl;
        getline(cin,clasificacionPelicula);
        banderaDeError=registro.setClasificacionPelicula(clasificacionPelicula);
        if(!banderaDeError)
        {
            cout<<"Error con la carga la clasificacion de la pelicula, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }
    }
    banderaDeError=false;

    /// POR DEFECTO QUEREMOS QUE LAS PELICULAS NUEVAS SE CREEN FUERA DE CARTELERA
    registro.setEstado(false);


    fechaDeEstreno.cargarFecha();

    if(banderaDeCarga&&!banderaDeError)
    {
        if(_archiPeli.guardarPelicula(registro))
        {
            cout<< "LA PELICULA SE GUARDO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<< "LA PELICULA NO SE PUDO GUARDAR"<<endl;
        }
    }
    system("pause");
    system("cls");
}

void ManagerPeliculas::mostrarPeliculas()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;///puntero
/// ----> conseguimos los datos necesarios
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    if(cantidadDePeliculas>0)
    {
        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return;
        }/// se valido la optencion de memoria
        if(_archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas))
        {
            for(int i=0; i<cantidadDePeliculas; i++)
            {
                mostrarPelicula(vecPeliculas[i]);
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout<<"NO HAY PELICULAS PARA MOSTRAR"<<endl;
    }
    system("pause");
    system("cls");
}


void ManagerPeliculas::mostrarPelicula(Pelicula reg)
{
    cout<< "-----------------------------------"<<endl;
    cout<< "El nombre de la pelicula es: "<<reg.getNombrePelicula()<<endl;
    cout<< "El nombre del director es: "<< reg.getNombreDelDirector()<<endl;
    cout<< "El apellido del director es: "<< reg.getApellidoDelDirector()<<endl;
    cout<< "El genero de la pelicula es: "<< reg.getGeneroPelicula()<<endl;
    cout<< "La clasificacion de la pelicula es: "<<reg.getClasificacionPelicula()<<endl;
    cout<< "LA FECHA DE ESTRENO ES: ";
    reg.getFechaDeEstreno().mostrarFecha();
    if(reg.getEstado())
    {
        cout<< "la pelicula esta en cartelera"<<endl;
    }
    else
    {
        cout<< "la pelicula no esta en cartelera"<<endl;
    }
    cout<< "-----------------------------------"<<endl;
}
/// funcion numero 3 del menu pelicula, ayuda con la funcion del menu 4 y menu 5
int ManagerPeliculas::buscarPosicionPeliculaPorID()
{
    int ID;
    int posicion=-1;
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    if(cantidadDePeliculas>0)
    {
        cout<< "INGRESE EL ID DE LA PELICULA: "<<endl;
        cin>>ID;

        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return -1;
        }/// se valido la optencion de memoria

        _archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas);

        for(int i=0; i<cantidadDePeliculas; i++)
        {
            if(ID==vecPeliculas[i].getNumeroDeID())
            {
                delete[] vecPeliculas;
                posicion=i;
                return posicion;
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout<<"NO HAY PELICULA PARA BUSCAR"<<endl;
    }
    system("pause");
    system("cls");
    return posicion;
}

/// OPCION 4 DEL MENU DE PELICULAS
void ManagerPeliculas::sacarDeCartelera()
{
    int posicion;
    Pelicula registro;
    posicion=buscarPosicionPeliculaPorID();
    if(posicion!= -1) /// si el valor de posicion fuese -1 quiere decir que no se encontro una posicion para la pelicula;
    {
        if(_archiPeli.bajaLogicaPelicula(registro, posicion))
        {
            cout<< "LA PELICULA FUE QUITADA CON EXITO"<<endl;
        }
        else
        {
            cout<< "LA PELICULA NO ESTABA EN CARTELERA"<<endl;
        }
        system("pause");
        system("cls");
    }
}
/// OPCION 5 DEL MENU DE PELICULAS
void ManagerPeliculas::ponerEnCartelera()
{
    int posicion;
    Pelicula registro;
    posicion=buscarPosicionPeliculaPorID();

    if(posicion!= -1) /// si el valor de posicion fuese -1 quiere decir que no se encontro una posicion para la pelicula;
    {
        if(_archiPeli.altaLogicaPelicula(registro, posicion))
        {
            cout<< "LA PELICULA FUE AGREGADA CON EXITO"<<endl;
        }
        else
        {
            cout<< "LA PELICULA YA ESTABA EN CARTELERA"<<endl;
        }
        system("pause");
        system("cls");
    }
}



/// ESTA FUNCION LA USAMOS EN LA OPCION 6 DEL MENU DE PELICULAS
void ManagerPeliculas::mostrarPeliculasEnCartelera()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
/// ----> conseguimos los datos necesarios
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    if(cantidadDePeliculas>0)
    {
        vecPeliculas=new Pelicula[cantidadDePeliculas];
        if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
            return;
        }/// se valido la optencion de memoria
        _archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas);
        {
            /// falta validar si consiguio memoria
            for(int i=0; i<cantidadDePeliculas; i++)
            {
                if(vecPeliculas[i].getEstado())
                {
                    mostrarPelicula(vecPeliculas[i]);
                }
            }
        }
        delete[] vecPeliculas;
    }
    else
    {
        cout << "NO SE PUDIERON LEER LAS PELICULAS" << endl;
    }
}

/// FUNCION PARA USAR EN LA COMPRA DE ENTRADAS
Pelicula* ManagerPeliculas::traerPeliculasEnCartelera()
{
/// ----> VARIABLES
    int cantidadDePeliculas;
    int cantidadDePeliculasEnCartelera;
    Pelicula *vecPeliculas;
    Pelicula *vecPeliCartelera;/// memoria dinamica para eliminar en la otra funcion
    int pos=0;
/// ----> conseguimos los datos necesarios
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    cantidadDePeliculasEnCartelera=_archiPeli.getCantidadPeliculasEnCartelera();
    vecPeliculas=new Pelicula[cantidadDePeliculas];
    if (vecPeliculas == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
        }/// se valido la obtencion de memoria
    vecPeliCartelera=new Pelicula[cantidadDePeliculasEnCartelera];
    if (vecPeliCartelera == nullptr)
        {
            cout << "No se pudo reservar memoria para las películas." << endl;
        }/// se valido la obtencion de memoria
    if(_archiPeli.leerTodas(vecPeliculas,cantidadDePeliculas))
    {
        /// falta validar si consiguio memoria
        for(int i=0; i<cantidadDePeliculas; i++)
        {
            if(vecPeliculas[i].getEstado())
            {
                vecPeliCartelera[pos]=vecPeliculas[i];
                pos++;
            }
        }
    }
    else
    {
        cout << "NO SE PUDIERON LEER LAS PELICULAS" << endl;
    }
    delete[] vecPeliculas;
    return vecPeliCartelera;
}
/// retornar la cantidad de peliculas que hay en cartelera
int ManagerPeliculas::cantidadPeliculasEnCartelera()
{
    int cantidadDePeliculasEnCartelera;
    cantidadDePeliculasEnCartelera=_archiPeli.getCantidadPeliculasEnCartelera();
    return cantidadDePeliculasEnCartelera;
}

bool ManagerPeliculas::verificarSiExiste(string nombrePelicula){
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;
    cantidadDePeliculas=_archiPeli.getCantidadPeliculas();
    vecPeliculas=new Pelicula[cantidadDePeliculas];
    for(int i=0;i<cantidadDePeliculas;i++){
        if(vecPeliculas[i].getNombrePelicula()==nombrePelicula){
            cout<<"encontrado"<<endl;
            delete[] vecPeliculas;
            return true;
        }
    }
    delete[] vecPeliculas;
    return false;
}
