#include"Persona.h"
#include <fstream>

class Autor : public Persona
{
    private:
        string medio;
    public:
        Autor();
        Autor(int dni , string nom , string medio);
        string getmedio () ;
        void guardarAutor();
};


