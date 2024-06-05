#include"Persona.h"

class Autor : public Persona
{
    private:
        string medio;
    public:
        Autor();
        Autor(int dni,string nom, string medio);
};


