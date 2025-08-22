#include <iostream>
#include<limits>
#include "Clientes.h"
#include "Fecha.h"
#include<cstring>
#include "Constante.h"
#include "ArchivoClientes.h"

Clientes::Clientes()
{
    strcpy(_nombreCliente,"");
    strcpy(_apellidoCliente,"");
    strcpy(_emailCliente, "");
    _dniCliente=1000000;
    _estado=true;


}
Clientes::Clientes(string nombreCliente, string apellidoCliente, string emailCliente, int dniCliente, bool estado)
{
    setNombreCliente(nombreCliente);
    setApellidoCliente(apellidoCliente);
    setEmailCliente(emailCliente);
    setDniCliente(dniCliente);
    setEstado(estado);

}
///getters

string Clientes::getNombreCliente()
{
    return _nombreCliente;
}
string Clientes::getApellidoCliente()
{
    return _apellidoCliente;
}
string Clientes::getEmailCliente()
{
    return _emailCliente;
}

int Clientes::getDniCliente()
{
    return _dniCliente;
}

bool Clientes::getEstado()
{
    return _estado;
}

///setters
void Clientes::setNombreCliente(string nombreCliente)
{
    strcpy(_nombreCliente, nombreCliente.c_str());
}
void Clientes::setApellidoCliente(string apellidoCliente)
{

    strcpy(_apellidoCliente, apellidoCliente.c_str());
}

void Clientes::setEmailCliente(string emailCliente)
{
    strcpy(_emailCliente, emailCliente.c_str());

}
void Clientes::setDniCliente(int dniCliente)
{
    _dniCliente=dniCliente;

}
void Clientes::setEstado(bool estado)
{
    _estado=estado;

}

bool Clientes::cargarCliente()
{
    string nombreCliente;
    string apellidoCliente;
    string emailCliente;
    int dniCliente;
    bool estado=true;

    ArchivoClientes archivoCliente;
    int contadorDeErrores=0;
    bool esDatoValido=false;
    while(contadorDeErrores<3)
    {
        cout << "Ingrese DNI: ";
        dniCliente=validarEntero();
        estado=archivoCliente.getPosicion(dniCliente)==-1 && dniCliente>1000000;
        if(estado)
        {
            setDniCliente(dniCliente);
            contadorDeErrores=0;
            break;

        }
        else
        {
            if(archivoCliente.getPosicion(dniCliente)!=-1)
            {
                cout<<"El dni ya se encuentra registrado"<<endl;
            }
            if(dniCliente<=1000000)
            {
                cout<<"El DNI debe ser mayor a 1000000"<<endl;
            }
            contadorDeErrores++;

        }
    }

    while(contadorDeErrores<3)
    {
        cout<<"Ingrese su email"<<endl;
        cin.ignore();
        getline(cin, emailCliente);
        bool noExiste = archivoCliente.getPosicion(emailCliente) == -1;
        bool longitudValida = emailCliente.length() > 0 && emailCliente.length() < TAMANIOCHARMEDIO;
        bool formatoValido = validarEmail(emailCliente);
        estado=noExiste && longitudValida && formatoValido;
        if(estado)
        {
            setEmailCliente(emailCliente);
            contadorDeErrores=0;
            break;
        }
        else
        {
            if(!noExiste)
            {
                cout<<"El email que intenta registrar ya se encuentra registrado"<<endl;
            }
            if(!longitudValida)
            {
                cout<<"El email debe tener entre 1 y " << TAMANIOCHARMEDIO << " caracteres"<<endl;
            }

            if(!formatoValido)
            {
                cout<<"Email ingresado es invalido"<<endl;
            }
            contadorDeErrores++;
        }
    }


    while(contadorDeErrores <3 )
    {
        cout<< "Ingrese el nombre del cliente: "<<endl;
        getline(cin,nombreCliente);
        pasarAMinusculas(nombreCliente);
        esDatoValido=nombreCliente.length()>0 && nombreCliente.length()<TAMANIOCHARMEDIO;

        if(esDatoValido)
        {
            strcpy(_nombreCliente,nombreCliente.c_str());
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "NO ES UN NOMBRE VALIDO EL QUE DESEA INGRESAR"<<endl;
            contadorDeErrores++;
        }

    }

    while(contadorDeErrores<3)
    {
        cout<<"Ingrese el apellido del cliente"<<endl;
        getline(cin, apellidoCliente);
        pasarAMinusculas(apellidoCliente);
        esDatoValido=apellidoCliente.length() > 0 && apellidoCliente.length() < TAMANIOCHARMEDIO;


        if(esDatoValido)
        {
            strcpy(_apellidoCliente,apellidoCliente.c_str());
            contadorDeErrores=0;
            break;
        }
        else
        {
            cout<< "NO ES UN NOMBRE VALIDO EL QUE DESEA INGRESAR"<<endl;
            contadorDeErrores++;
        }

    }
    if(contadorDeErrores<3)
    {
        setEstado(true);
    }
    return contadorDeErrores<3;
}

void Clientes::mostrarCliente()
{
    cout << "------------------------------" << endl;
    cout << "DNI: " << getDniCliente()<< endl;
    cout << "Nombre: " << getNombreCliente() << endl;
    cout << "Apellido: " << getApellidoCliente() << endl;
    cout << "Email: " << getEmailCliente() << endl;
    if(getEstado())
    {
        cout<< "EL CLIENTE ESTA ACTIVO" <<endl;
    }
    if(!getEstado())
    {
        cout<< "EL CLIENTE NO  ESTA ACTIVO" <<endl;
    }
    cout << "------------------------------" << endl;
}

bool Clientes::validarEmail(const string& emailCliente)
{
    size_t arrobaPos=emailCliente.find('@');
    if(arrobaPos==string::npos || arrobaPos==0 || arrobaPos==emailCliente.length()-1)
    {
        return false;
    }
    if(emailCliente.find('@', arrobaPos +1)!= string::npos)
    {
        return false;
    }
    return true;
}
void Clientes::pasarAMinusculas(string &cadena)
{
    for (char &caracter : cadena)
    {
        caracter = std::tolower(static_cast<unsigned char>(caracter));
    }
}

int Clientes::validarEntero()
{
    int entero;
    while (true)
    {
        cin >> entero;

        if (cin.fail())
        {
            cout << "Entrada invalida. Intente nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            // Siempre limpiar el resto de la línea
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entero;
        }
    }
}
