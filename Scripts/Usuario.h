#include <iostream>
#include <fstream>
#include "Persona.h"
using namespace std;

class Usuario : public Persona
{
    public:
        int edad;
        Usuario(int dni,string nom,int ed);

        void guardarUsuario();
        void cargarUsuario();

        int getDni();
        string getNombre();
        int getEdad();
};