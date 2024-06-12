#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>   
using namespace std;

class Persona
{
    protected:
        string DNI;
        string nombre;
    public:
        Persona();
        Persona(string dni,string nom);
        string getDni() const;
        string getNombre() const;
};
#endif 
