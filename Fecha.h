#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED



class Fecha{
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    bool cargarFecha();
    void mostrarFecha();
    int validarEntero();
    bool esFechaValida(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
private:
    int _dia;
    int _mes;
    int _anio;
};


#endif // FECHA_H_INCLUDED
