#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "ManagerPeliculas.h"
#include "ManagerSalas.h"
#include "ManagerEntrada.h"
#include "ManagerRespaldo.h"
#include "Informes.h"
class Menu{
public:
    void mostrarMenuPrincipal();
    void menuPelicula();
    void menuSalas();
    void menuEntradas();
    void menuRespaldo();
    void menuInformes();
private:
    int _opcionPrincipal;
    int _opcionPelicula;
    int _opcionSala;
    int _opcionEntrada;
    int _opcionRespaldo;
    int _opcionInforme;

    ManagerPeliculas _managerMovies;
    ManagerSalas _ManagerSalas;
    ManagerEntrada _managerEntradas;
    ManagerRespaldo _managerRespaldo;
    Informes _informe;
};

#endif // MENU_H_INCLUDED
