#include <iostream>
#include "Persona.h"
using namespace std;

class Usuario : public Persona
{
    private:
        int edad;
    public:
        Usuario(int dni,string nom,int ed);
        void GuardarUsuario();
};