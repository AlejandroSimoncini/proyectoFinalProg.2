#include <iostream>
#include "Persona.h"
using namespace std;

class Usuario : public Persona
{
    private:
        int edad;
    public:
        Usuario();
        Usuario(string dni,string nom,int ed);
        int getEdad();
        string toString();
        static Usuario fromString(string& datos);
};