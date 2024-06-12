#include <iostream>
#include <string>
#include <sstream>
#include "Usuario.h"
using namespace std;

Usuario::Usuario() : Persona()
{
    edad = 0;
}

Usuario::Usuario(string dni, string nom,int ed) : Persona(dni, nom)
{
    edad = ed;
}

int Usuario::getEdad()
{
    return edad;
}

string Usuario::toString()
{
    return DNI + "," + nombre + "," + to_string(edad);
}

Usuario Usuario::fromString(string& datos)
{
    stringstream ss(datos);
    string dni, nombre, edadStr;
    getline(ss, dni, ',');
    getline(ss, nombre, ',');
    getline(ss, edadStr, ',');
    int edad = stoi(edadStr);
    return Usuario(dni, nombre, edad);
}

