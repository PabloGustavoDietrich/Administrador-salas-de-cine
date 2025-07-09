#include <iostream>
using namespace std;
#include<cstring>
#include "Pelicula.h"
#include "ArchivoPelicula.h"
Pelicula::Pelicula() {}

Pelicula::Pelicula(int ID, string nombrePelicula,string nombreDirector,string apellidoDirector,string generoPelicula,string clasificacionPelicula,bool estado, Fecha fechaDeEstreno)
{
    setNumeroID(ID);
    setNombrePelicula(nombrePelicula);
    setNombreDelDirector(nombreDirector);
    setApellidoDelDirector(apellidoDirector);
    setGeneroPelicula(generoPelicula);
    setClasificacionPelicula(clasificacionPelicula);
    setEstado(estado);
    setFechaDeEstreno(fechaDeEstreno);
}

bool Pelicula::cargarPelicula()
{
//////////// VARIABLES DE LA PELICULA ////////////////
    string nombrePelicula;
    string nombreDelDirector;
    string apellidoDelDirector;
    string generoPelicula;
    string clasificacionPelicula;
    Fecha fechaDeEstreno;
    int estado;
//// VARIABLES DEL ARCHIVO ////////////////
    ArchivoPelicula archivoPelicula;
    int cantidadDePeliculas;
    Pelicula *vecPeliculas;

    bool banderaDeCarga=true;//// si no se desea carga mas datos la pasamos a false
    bool esDatoValido=false;

    cantidadDePeliculas=archivoPelicula.getCantidadPeliculas();
    vecPeliculas=new Pelicula[cantidadDePeliculas];
    archivoPelicula.leerTodas(vecPeliculas,cantidadDePeliculas);

    if(cantidadDePeliculas<0) ///si no hay peliculas nos llega un -1
    {
        setNumeroID(1);
    }
    else
    {
        setNumeroID(cantidadDePeliculas+1);
    }

    cin.ignore();

    while(banderaDeCarga&& !esDatoValido)
    {
        cout<< "Ingrese el nombre de la Pelicula: "<<endl;
        getline(cin,nombrePelicula);
        pasarAMinusculas(nombrePelicula);
        bool encontro=false;

        for(int i=0; i<cantidadDePeliculas; i++)
        {
            string nombreAComparar=vecPeliculas[i].getNombrePelicula();
            pasarAMinusculas(nombreAComparar); ///despues de guardar directamente en minusculas todo esta linea se puede borrar
            if(nombreAComparar==nombrePelicula)
            {
                encontro=true;
            }
        }
        esDatoValido=nombrePelicula.length()> 0 && nombrePelicula.length() < TAMANIOCHARMEDIO && !encontro;
        if (!esDatoValido)
        {
            cout<<"Error con la carga del nombre, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }else{
            setNombrePelicula(nombrePelicula);
        }
    }
    esDatoValido=false;

    while(banderaDeCarga&& !esDatoValido){

        cout<< "Ingrese nombre del Director: "<<endl;
        getline(cin,nombreDelDirector);

        esDatoValido=nombreDelDirector.length() > 0 && nombreDelDirector.length() < TAMANIOCHARMEDIO;
        if(!esDatoValido)
        {
            cout<<"Error con la carga del nombre, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();///en este caso en importante dejar el ignore aca distinto de la carga anterior
        }else{
            setNombreDelDirector(nombreDelDirector);
        }
    }
    esDatoValido=false;

    while(banderaDeCarga&& !esDatoValido){

        cout<< "Ingrese apellido del Director: "<<endl;
        getline(cin,apellidoDelDirector);

        esDatoValido=apellidoDelDirector.length() > 0 && apellidoDelDirector.length() < TAMANIOCHARMEDIO;
        if(!esDatoValido)
        {
            cout<<"Error con la carga del apellido, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();///en este caso en importante dejar el ignore aca distinto de la carga anterior
        }else{
            setNombreDelDirector(apellidoDelDirector);
        }
    }
    esDatoValido=false;

    while(banderaDeCarga&&!esDatoValido)
    {
        cout<< "ingrese el genero de la pelicula: "<<endl;
        getline(cin,generoPelicula);
        string generos[] = {"accion","aventura","animacion","comedia","drama","terror","ciencia ficcion","fantasia","documental","musical","romance","misterio","suspenso","crimen","guerra","historica","western","biografia","familia","deporte"};
        pasarAMinusculas(generoPelicula);
        bool encontro=false;
        for(int i=0;i<20;i++){
            if(generoPelicula==generos[i]){
                encontro=true;
            }
        }
        esDatoValido=generoPelicula.length() > 0 && generoPelicula.length() < TAMANIOCHARMEDIO && encontro;
        if(!esDatoValido)
        {
            cout<<"Error con la carga del genero de la pelicula, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }else{setGeneroPelicula(generoPelicula);}
    }
    esDatoValido=false;

    while(banderaDeCarga&&!esDatoValido)
    {
        int clasificacionElegida;
        cout<< "ingrese el numero de la clasificacion de la pelicula: (1= ATP, 2= mayores de 14 o 3= mayores de 18)"<<endl;
        cin>>clasificacionElegida;
        cin.ignore();
        switch(clasificacionElegida){
            case 1: clasificacionPelicula="atp";
                    esDatoValido=true;
                    break;
            case 2: clasificacionPelicula="mayores de 14";
                    esDatoValido=true;
                    break;
            case 3: clasificacionPelicula="mayores de 18";
                    esDatoValido=true;
                    break;
            default:
                cout<<"Error con la carga la clasificacion de la pelicula, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
                cin>>banderaDeCarga;
                cin.ignore();
        }
        if(esDatoValido)
        {
            setClasificacionPelicula(clasificacionPelicula);
        }
    }
    esDatoValido=false;

    banderaDeCarga=fechaDeEstreno.cargarFecha();
    if(banderaDeCarga){
        setFechaDeEstreno(fechaDeEstreno);
    }
    while(banderaDeCarga&&!esDatoValido){
        cout<<"LA PELICULA ESTA EN CARTELERA (1 si esta, 0 sino esta) "<<endl;
        cin>>estado;
        cin.ignore();
        esDatoValido=estado==0||estado==1;
        if(!esDatoValido){
            cout<<"Error con la carga del estado de la pelicula, (presione 1 si desea seguir intentando o 0 si desea dejar de cargar y salir)"<<endl;
            cin>>banderaDeCarga;
            cin.ignore();
        }else{
            setEstado(estado);
        }
    }
    delete[] vecPeliculas;

    return banderaDeCarga;
}

void Pelicula::mostrarPelicula()
{
    cout<< "-----------------------------------"<<endl;
    cout<< "El nombre de la pelicula es: "<<getNombrePelicula()<<endl;
    cout<< "El nombre del director es: "<< getNombreDelDirector()<<endl;
    cout<< "El apellido del director es: "<< getApellidoDelDirector()<<endl;
    cout<< "El genero de la pelicula es: "<< getGeneroPelicula()<<endl;
    cout<< "La clasificacion de la pelicula es: "<<getClasificacionPelicula()<<endl;
    cout<< "LA FECHA DE ESTRENO ES: ";
    getFechaDeEstreno().mostrarFecha();
    if(getEstado())
    {
        cout<< "la pelicula esta en cartelera"<<endl;
    }
    else
    {
        cout<< "la pelicula no esta en cartelera"<<endl;
    }
    cout<< "-----------------------------------"<<endl;
}

/// ESTA FUNCION RECIBE UN STRING, Y CADA CARACTER DE ESE STRING SE VA PASANDO A MINUSCULA
void Pelicula::pasarAMinusculas(string &cadena)
{
    for (char &caracter : cadena)
    {
        caracter = std::tolower(static_cast<unsigned char>(caracter));
    }
}

void Pelicula::setNumeroID(int peliculaID)
{
    _peliculaID=peliculaID;
}
void Pelicula::setNombrePelicula(string nombrePelicula)
{
    strcpy(_nombrePelicula,nombrePelicula.c_str());
}
void Pelicula::setNombreDelDirector(string nombreDirector)
{
        strcpy(_nombreDelDirector,nombreDirector.c_str());
}
void Pelicula::setApellidoDelDirector(string apellidoDirector)
{
    strcpy(_apellidoDelDirector,apellidoDirector.c_str());
}
void Pelicula::setGeneroPelicula(string generoPelicula)
{
    strcpy(_generoPelicula,generoPelicula.c_str());
}
void Pelicula::setClasificacionPelicula(string clasificacionPelicula)
{
    strcpy(_clasificacionPelicula,clasificacionPelicula.c_str());
}
void Pelicula::setFechaDeEstreno(Fecha fechaDeEstreno)
{
    _fechaDeEstreno=fechaDeEstreno;
}
void Pelicula::setEstado(bool estado)
{
    _estado=estado;
}

int Pelicula::getNumeroDeID()
{
    return _peliculaID;
}
string Pelicula::getNombrePelicula()
{
    return _nombrePelicula;
}
string Pelicula::getNombreDelDirector()
{
    return _nombreDelDirector;
}
string Pelicula::getApellidoDelDirector()
{
    return _apellidoDelDirector;
}
string Pelicula::getGeneroPelicula()
{
    return _generoPelicula;
}
string Pelicula::getClasificacionPelicula()
{
    return _clasificacionPelicula;
}
Fecha Pelicula::getFechaDeEstreno()
{
    return _fechaDeEstreno;
}

bool Pelicula::getEstado()
{
    return _estado;
}
