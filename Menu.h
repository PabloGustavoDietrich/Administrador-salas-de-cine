#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "ManagerPeliculas.h"
#include "ManagerSalas.h"
#include "ManagerEntrada.h"
#include "ManagerRespaldo.h"
#include "Informes.h"
#include "ManagerGenero.h"
#include "ManagerClientes.h"
class Menu{
public:
    void mostrarMenuPrincipal();
    void menuPelicula();
    void menuSalas();
    void menuEntradas();
    void menuGenero();
    void menuCliente();
    void menuRespaldo();
    void menuInformes();
private:
    int _opcionPrincipal;
    int _opcionPelicula;
    int _opcionSala;
    int _opcionEntrada;
    int _opcionGenero;
    int _opcionCliente;
    int _opcionRespaldo;
    int _opcionInforme;

    ManagerPeliculas _managerMovies;
    ManagerSalas _ManagerSalas;
    ManagerEntrada _managerEntradas;
    ManagerRespaldo _managerRespaldo;
    Informes _informe;
    ManagerGenero _managerGenero;
    ManagerClientes _managerCliente;
};

#endif // MENU_H_INCLUDED
