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

    int contadorDeErrores=0;
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

    while(contadorDeErrores<3)
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
        if (esDatoValido)
        {
            setNombrePelicula(nombrePelicula);
            contadorDeErrores=0;
            break;
        }
        else
        {
            if(encontro)cout<<"ESA PELICULA YA ESTA GUARDADA, POR FAVOR INGRESE OTRA"<<endl;
            if(!encontro)cout<<"ERROR CON EL INGRESO DEL NOMBRE DE LA PELICULA"<<endl;
            contadorDeErrores++;
        }
    }

    while(contadorDeErrores<3)
    {

        cout<< "Ingrese nombre del Director: "<<endl;
        getline(cin,nombreDelDirector);

        esDatoValido=nombreDelDirector.length() > 0 && nombreDelDirector.length() < TAMANIOCHARMEDIO;
        if(esDatoValido)
        {
            setNombreDelDirector(nombreDelDirector);
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "ERROR EN LA CARGA DEL NOMBRE DEL DIRECTOR" <<endl;
            contadorDeErrores++;
        }
    }

    while(contadorDeErrores<3)
    {

        cout<< "Ingrese apellido del Director: "<<endl;
        getline(cin,apellidoDelDirector);

        esDatoValido=apellidoDelDirector.length() > 0 && apellidoDelDirector.length() < TAMANIOCHARMEDIO;
        if(esDatoValido)
        {
            setApellidoDelDirector(apellidoDelDirector);
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "ERROR EN LA CARGA DEL APELLIDO DEL DIRECTOR" <<endl;
            contadorDeErrores++;
        }
    }

    while(contadorDeErrores<3)
    {
        cout<< "ingrese el genero de la pelicula: "<<endl;
        getline(cin,generoPelicula);
        string generos[] = {"accion","aventura","animacion","comedia","drama","terror","ciencia ficcion","fantasia","documental","musical","romance","misterio","suspenso","crimen","guerra","historica","western","biografia","familia","deporte"};
        pasarAMinusculas(generoPelicula);
        esDatoValido=false;
        for(int i=0; i<20; i++)
        {
            if(generoPelicula==generos[i])
            {
                esDatoValido=true;
            }
        }
        if(esDatoValido)
        {
            setGeneroPelicula(generoPelicula);
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "ERROR EN LA CARGA DEL GENERO DE LA PELICULA" <<endl;
            contadorDeErrores++;
        }
    }

    while(contadorDeErrores<3)
    {
        int clasificacionElegida;
        cout<< "ingrese el numero de la clasificacion de la pelicula: (1= ATP, 2= mayores de 14 o 3= mayores de 18)"<<endl;
        cin>>clasificacionElegida;
        cin.ignore();
        switch(clasificacionElegida)
        {
        case 1:
            clasificacionPelicula="atp";
            esDatoValido=true;
            break;
        case 2:
            clasificacionPelicula="mayores de 14";
            esDatoValido=true;
            break;
        case 3:
            clasificacionPelicula="mayores de 18";
            esDatoValido=true;
            break;
        default:
            cout<< "ERROR EN LA CARGA DE LA CLASIFICACION DE LA PELICULA" <<endl;
            esDatoValido=false;
            contadorDeErrores++;
        }
        if(esDatoValido)
        {
            setClasificacionPelicula(clasificacionPelicula);
            contadorDeErrores=0;
            break;
        }
    }

    if(contadorDeErrores<3)
    {
        if(fechaDeEstreno.cargarFecha())
        {
            setFechaDeEstreno(fechaDeEstreno);
        }
        else
        {
            contadorDeErrores=3;/// ya que no se cargo una fecha valida
        }
    }
    while(contadorDeErrores<3)
    {
        cout<<"LA PELICULA ESTA EN CARTELERA (1 si esta, 0 sino esta) "<<endl;
        cin>>estado;
        cin.ignore();
        esDatoValido=estado==0||estado==1;
        if(esDatoValido)
        {
            setEstado(estado);
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "ERROR CON EL NUMERO INGRESADO"<<endl;
            contadorDeErrores++;
        }
    }
    delete[] vecPeliculas;

    return contadorDeErrores<3;/// retornamos una expresion booleana ya que si no fuese menor que 3 es que en algun lado del codigo se equivoco y no se cargaron datos validos
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
void Pelicula::mostrarPeliculaYID()
{
    cout<< "-----------------------------------"<<endl;
    cout<< "El ID de la pelicula es: "<< getNumeroDeID()<<endl;
    cout<< "El nombre de la pelicula es: "<<getNombrePelicula()<<endl;
}

void Pelicula::mostrarPeliculaIDYCartelera()
{
    cout<< "-----------------------------------"<<endl;
    cout<< "El ID de la pelicula es: "<< getNumeroDeID()<<endl;
    cout<< "El nombre de la pelicula es: "<<getNombrePelicula()<<endl;

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
