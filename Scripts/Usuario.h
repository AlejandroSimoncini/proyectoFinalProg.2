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
        string toString() const;
        static Usuario fromString(const string& datos);
};