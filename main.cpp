#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
///void cargaMasivaSalas(ArchivoSala& archivo, int anio, int mes);
int main()
{
    Menu miMenu;
    miMenu.mostrarMenuPrincipal();





    return 0;
}
///     ArchivoSala archivo;
///ultima carga realizada cargaMasivaSalas(archivo, 2025, 10); octubre 2025
/*void cargaMasivaSalas(ArchivoSala& archivo, int anio, int mes) {
    int numeroSala = archivo.getCantidadSalas() + 1;  // continua desde lo que ya exista

    string tipos[] = {"estandar", "premium", "confort plus"};
    int tipoIndex = 0;

    for (int dia = 1; dia <= 31; dia++) {
        Fecha fecha(dia, mes, anio);

        if (!fecha.esFechaValida(dia, mes, anio)) continue;  // fecha inválida: no intento cargar

        for (int i = 1; i <= 6; i++) {
            string nombre = "sala " + to_string(i);
            string tipo = tipos[tipoIndex];
            bool estado = true;

            Sala nuevaSala(numeroSala, nombre, tipo, estado, fecha);

            if (archivo.guardarSala(nuevaSala)) {
                cout << "Se cargo sala #" << numeroSala << " (" << nombre
                     << ") tipo: " << tipo
                     << " para el " << dia << "/" << mes << "/" << anio << endl;
                numeroSala++;  // solo aumento si la guardé
            } else {
                cout << "Error al guardar " << nombre << endl;
            }

            tipoIndex = (tipoIndex + 1) % 3;  // rota entre los 3 tipos
        }
    }

    cout << "Carga masiva completada." << endl;
    system("pause");
    system("cls");
}*/
