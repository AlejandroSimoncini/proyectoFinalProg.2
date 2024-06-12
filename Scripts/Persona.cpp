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

string Persona::getNombre() const 
{
    return nombre;
}

string Persona::getDni() const
{
    return DNI;
}

