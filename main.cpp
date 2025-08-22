#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
#include "Clientes.h"
#include "ArchivoClientes.h"
#include "ArchivoPelicula.h"
#include "Fecha.h"

int main()
{
    Menu miMenu;
    miMenu.mostrarMenuPrincipal();

    /*Fecha fechaDeHoy;
    Fecha fechaelegida;
    fechaDeHoy.setHoy();
    fechaelegida.cargarFecha();
    if(fechaelegida<fechaDeHoy){
        cout<< "ES UNA FECHA INVALIDA O DE AYER";
    }*/

    return 0;
}

