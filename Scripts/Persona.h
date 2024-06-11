#include<string> 
#include<iostream>   
using namespace std;

class Persona
{
public:
    string Nombre;
    int DNI;
    Persona(int dni, string nom);
    string getNombre();
    int getDni();
};

