#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
#include "Constante.h"
#include <string>

using namespace std;

class Sala{

public:
    Sala();
    Sala(int numero,string nombre,int tipo,bool estadoSala);

    int getnumero();
    string getnombre();
    int gettipo();
    bool getEstadoSala();
    bool getButaca(int fila, int columna);

    void setButacas();
    void setButaca(int fila,int columna,bool estado);
    void setnumero(int numero);
    bool setnombre(string nombre);
    bool settipo(int tipo);
    void setEstado(bool estadoSala);

private:
    int _numero;
    char _nombre[TAMANIOCHARMEDIO];
    int _tipo;
    bool _butacas[FILAS][COLUMNAS];
    bool _estadoSala;

};








#endif // SALA_H_INCLUDED
