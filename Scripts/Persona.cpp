#include <iostream>
#include "Persona.h"

Persona::Persona(int dni, string nom) 
{
    Nombre = nom;
    DNI = dni;
}

string Persona::getNombre() 
{
    return Nombre;
}

int Persona::getDni()
{
    return DNI;
}

