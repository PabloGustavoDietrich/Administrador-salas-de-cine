#include <iostream>
using namespace std;

#include "Menu.h"

void Menu::mostrarMenuPrincipal()
{
    do
    {
        cout<<"-----------> BIENVENIDO AL CINE FAFY&PANCHO <--------------"<<endl;
        cout<<"-------> PODES ACCEDER A LOS SIGUIENTES MENUES <-----------"<<endl;
        cout<<"OPCION 1.- MENU DE PELICULAS"<<endl;
        cout<<"OPCION 2.- MENU DE SALAS"<<endl;
        cout<<"OPCION 3.- MENU DE ENTRADAS"<<endl;
        cout<<"OPCION 4.- MENU DE GENERO"<<endl;
        cout<<"OPCION 5.- MENU DE CLIENTE"<<endl;
        cout<<"OPCION 6.- MENU DE RESPALDOS"<<endl;
        cout<<"OPCION 7.- MENU DE INFORMES"<<endl;
        cout<<"OPCION 0.- SALIR DEL PROGRAMA"<<endl;
        cin>>_opcionPrincipal;

        system("cls");
        switch(_opcionPrincipal)
        {
        case 1:
            menuPelicula();
            break;
        case 2:
            menuSalas();
            break;
        case 3:
            menuEntradas();
            break;
        case 4:
            menuGenero();
            break;
        case 5:
            menuCliente();
            break;
        case 6:
            menuRespaldo();
            break;
        case 7:
            menuInformes();
            break;
        case 0:
            cout<<"saliste del programa "<<endl;
            break;
        default:
            cout<<"la opcion elegida es incorrecta"<<endl;
            break;

        }
    }
    while(_opcionPrincipal!=0);
}

void Menu::menuPelicula()
{
    do
    {
        cout<<"------------> SECCION PELICULAS <-------------"<<endl;
        cout<<"OPCION 1.- GUARDAR PELICULA"<<endl;
        cout<<"OPCION 2.- LISTAR PELICULAS"<<endl;
        cout<<"OPCION 3.- BUSCAR PELICULA POR ID"<<endl;
        cout<<"OPCION 4.- SACAR DE CARTELERA"<<endl;
        cout<<"OPCION 5.- PONER EN CARTELERA"<<endl;
        cout<<"OPCION 6.- LISTAR PELICULAS EN CARTELERA"<<endl;
        cout<<"OPCION 0.- SALIR DE PELICULAS"<<endl;
        cin>>_opcionPelicula;

        system("cls");
        switch(_opcionPelicula)
        {
        case 1:
            _managerMovies.cargarPelicula();
            break;
        case 2:
            _managerMovies.mostrarPeliculas();
            break;
        case 3:
            _managerMovies.mostrarPeliculasPorID();
            break;
        case 4:
            _managerMovies.sacarDeCartelera();
            break;
        case 5:
            _managerMovies.ponerEnCartelera();
            break;
        case 6:
            _managerMovies.mostrarPeliculasEnCartelera();
            system("pause");
            system("cls");
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION PELICULAS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionPelicula!=0);

}
void Menu::menuSalas()
{
    do
    {
        cout<<"------------> SECCION SALAS <-------------"<<endl;
        cout<<"OPCION 1.- GUARDAR SALA"<<endl;
        cout<<"OPCION 2.- LISTAR SALAS"<<endl;
        cout<<"OPCION 3.- BUSCAR SALA POR NUMERO"<<endl;
        cout<<"OPCION 4.- BAJA DE SALA POR MANTENIMIENTO"<<endl;
        cout<<"OPCION 5.- ALTA DE SALA POST MANTENIMIENTO"<<endl;
        cout<<"OPCION 6.- LISTAR SALAS POR FECHA"<<endl;
        cout<<"OPCION 0.- VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>_opcionSala;

        system("cls");
        switch(_opcionSala)
        {
        case 1:
            _ManagerSalas.cargarSala();
            break;
        case 2:
            _ManagerSalas.mostrarSalas();
            system("pause");
            system("cls");
            break;
        case 3:
            _ManagerSalas.mostrarSalaPorNumero();
            break;
        case 4:
            _ManagerSalas.bajaPorMantenimiento();
            break;
        case 5:
            _ManagerSalas.altaPostMantenimiento();
            break;
        case 6:
            _ManagerSalas.mostrarSalasPorFecha();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION SALAS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionSala!=0);


}

void Menu::menuEntradas()
{
    do
    {
        cout<<"------------> SECCION ENTRADAS <-------------"<<endl;
        cout<<"OPCION 1.- COMPRAR ENTRADA "<<endl;
        cout<<"OPCION 2.- LISTAR ENTRADAS COMPRADAS"<<endl;
        cout<<"OPCION 3.- LISTAR ENTRADAS COMPRADAS POR DNI"<<endl;
        cout<<"OPCION 4.- LISTAR ENTRADAS COMPRADAS POR FECHA"<<endl;
        cout<<"OPCION 5.- LISTAR ENTRADAS COMPRADAS POR PELICULA"<<endl;
        cout<<"OPCION 0.- SALIR DE ENTRADAS"<<endl;
        cin>>_opcionEntrada;

        system("cls");
        switch(_opcionEntrada)
        {
        case 1:
            _managerEntradas.cargarEntrada();
            break;
        case 2:
            _managerEntradas.mostrarEntradas();
            system("pause");
            system("cls");
            break;
        case 3:
            _managerEntradas.mostrarEntradasPorDNI();
            break;
        case 4:
            _managerEntradas.mostrarEntradasPorFecha();
            break;
        case 5:
            _managerEntradas.mostrarEntradasPorPelicula();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION ENTRADAS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionEntrada!=0);

}

void Menu::menuGenero()
{
    do
    {
        cout<<"------------> SECCION GENERO <-------------"<<endl;
        cout<<"OPCION 1.- GUARDAR GENERO"<<endl;
        cout<<"OPCION 2.- LISTAR GENEROS"<<endl;
        cout<<"OPCION 3.- BUSCAR GENERO POR CODIGO"<<endl;
        cout<<"OPCION 4.- BAJA DE GENERO"<<endl;
        cout<<"OPCION 5.- ALTA DE GENERO"<<endl;
        cout<<"OPCION 6.- LISTAR PELICULAS POR GENERO"<<endl;
        cout<<"OPCION 0.- VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>_opcionGenero;
        cin.ignore();

        system("cls");
        switch(_opcionGenero)
        {
        case 1:
            _managerGenero.cargarGenero();
            break;
        case 2:
            _managerGenero.mostrarGeneros();
            system("pause");
            system("cls");
            break;
        case 3:
            _managerGenero.mostrarGeneroPorCod();
            break;
        case 4:
            _managerGenero.bajaGenero();
            break;
        case 5:
            _managerGenero.altaGenero();
            break;
        case 6:
            _managerGenero.mostrarPeliculasPorGenero();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION GENERO"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(_opcionGenero!=0);
}

void Menu::menuCliente()
{
    do
    {
        cout<<"---------->SECCION CLIENTES<-----------"<<endl;
        cout<<"OPCION 1.-CARGAR CLIENTE"<<endl;
        cout<<"OPCION 2.-LISTAR CLIENTES"<<endl;
        cout<<"OPCION 3.-BAJA CLIENTE"<<endl;
        cout<<"OPCION 4.-ALTA CLIENTE"<<endl;
        cout<<"OPCION 0.-VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>_opcionCliente;
        system("cls");
        switch (_opcionCliente)
        {
        case 1:
            _managerCliente.cargarCliente();
            break;
        case 2:
            _managerCliente.listarClientes();
            system("pause");
            system("cls");
            break;
        case 3:
            _managerCliente.bajaCliente();
            break;
        case 4:
            _managerCliente.altaCliente();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION CLIENTES"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionCliente!=0);

}

void Menu::menuRespaldo()
{
    do
    {
        cout<< "---------------> SECCION RESPALDOS <---------------"<<endl;
        cout<< "OPCION 1.- RESPALDAR ENTRADAS"<<endl;
        cout<< "OPCION 2.- RECUPERAR ENTRADAS"<< endl;
        cout<< "OPCION 3.- RESPALDAR PELICULAS"<<endl;
        cout<< "OPCION 4.- RECUPERAR PELICULAS"<<endl;
        cout<< "OPCION 5.- RESPALDAR SALAS"<<endl;
        cout<< "OPCION 6.- RECUPERAR SALAS"<<endl;
        cout<< "OPCION 7.- RESPALDAR CLIENTES"<<endl;
        cout<< "OPCION 8.- RECUPERAR CLIENTES"<<endl;
        cout<< "OPCION 0.- SALIR DEL MENU RESPALDOS"<< endl;
        cin>> _opcionRespaldo;

        system("cls");
        switch(_opcionRespaldo)
        {
        case 1:
            _managerRespaldo.crearNuevoRespaldoEntradas();
            break;
        case 2:
            _managerRespaldo.traerElRespaldoDeEntradas();
            break;
        case 3:
            _managerRespaldo.crearNuevoRespaldoPeliculas();
            break;
        case 4:
            _managerRespaldo.traerElRespaldoDePeliculas();
            break;
        case 5:
            _managerRespaldo.crearNuevoRespaldoSalas();
            break;
        case 6:
            _managerRespaldo.traerElRespaldoDeSalas();
            break;
        case 7:
            _managerRespaldo.crearNuevoRespaldoClientes();
            break;
        case 8:
            _managerRespaldo.traerElRespaldoDeClientes();
            break;
        case 0:
            cout<< "SALISTE DE LA SECCION DE RESPALDOS"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<< "LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(_opcionRespaldo!=0);
}

void Menu::menuInformes()
{
    do
    {
        cout<<"------------> SECCION INFORMES <-------------"<<endl;
        cout<<"OPCION 1.- MOSTRAR TOTAL ENTRADAS VENDIDAS"<<endl;
        cout<<"OPCION 2.- MOSTRAR ENTRADAS VENDIDAS POR GENERO"<<endl;
        cout<<"OPCION 3.- MOSTRAR ENTRADAS VENDIDAS POR TITULO"<<endl;
        cout<<"OPCION 4.- MOSTRAR ENTRADAS VENDIDAS POR TIPO DE SALA"<<endl;
        cout<<"OPCION 5.- MOSTRAR RECUDACION"<<endl;
        cout<<"OPCION 0.- VOLVER AL MENU PRINCIPAL"<<endl;
        cin>>_opcionInforme;

        system("cls");
        switch(_opcionInforme)
        {
        case 1:
            _informe.mostrarCantidadDeEntradasVendidas();
            break;
        case 2:
            _informe.mostrarCantidadEntradasVendidasPorgenero();
            break;
        case 3:
            _informe.mostrarCantidadDeEntradasVendidasPorTitulo();
            break;
        case 4:
            _informe.mostrarCantidadDeEntradasVendidasPorTipoDeSala();
            break;
         case 5:
            _informe.mostrarRecaudacion();
            break;
        case 0:
            cout<<"SALISTE DE LA SECCION INFORMES"<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout<<"LA OPCION ELEGIDA ES INCORRECTA"<<endl;
            system("pause");
            system("cls");
            break;
        }

    }
    while(_opcionInforme!=0);

}

