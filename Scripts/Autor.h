#include <iostream>
#include"Persona.h"

class Autor : public Persona
{
    private:
        string medio;
    public:
        Autor();
        Autor(string dni , string nom , string med);
        string getMedio();
        string toString();
        static Autor fromString(string& datos);
};