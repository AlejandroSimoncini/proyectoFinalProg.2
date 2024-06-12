#include"Autor.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

Autor::Autor() : Persona()
{
    medio = "";
}

Autor::Autor(string dni , string nom , string medi):Persona(dni, nom)
{
    medio = medi;
}

string Autor::getMedio()
{
    return medio ;
}

string Autor::toString()
{
    return DNI + "," + nombre + "," + medio;
}

Autor Autor::fromString(string& datos)
{
    stringstream ss(datos);
    string dni,nombre,medio;
    getline(ss,dni,',');
    getline(ss, nombre, ',');
    getline(ss, medio, ',');
    return Autor(dni, nombre, medio);
}