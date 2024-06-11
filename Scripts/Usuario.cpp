#include <iostream>
#include<fstream>
#include "Usuario.h"
using namespace std;

Usuario::Usuario(int dni, string nom,int ed) : Persona(dni, nom)
{
    edad = ed;
}

int Usuario::getDni()
{
    return DNI;
}

string Usuario::getNombre()
{
    return Nombre;
}

int Usuario::getEdad()
{
    return edad;
}

void Usuario::guardarUsuario()
{
    ofstream escribirU("usuarios.txt");
    if (escribirU.is_open())
    {
        escribirU << Nombre << endl;
        escribirU << DNI << endl;
        escribirU << edad << endl;
        escribirU << endl;
    }
    
}