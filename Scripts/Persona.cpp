#include <iostream>
#include "Persona.h"

Persona::Persona()
{
    nombre = "";
    DNI = "";
}

Persona::Persona(string dni, string nom) 
{
    nombre = nom;
    DNI = dni;
}

string Persona::getNombre() 
{
    return nombre;
}

string Persona::getDni()
{
    return DNI;
}

