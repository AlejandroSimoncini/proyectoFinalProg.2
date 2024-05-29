#include <iostream>
using namespace std;

class Noticia
{
    private:
        string titulo;
        string detalle;
        int dia;
        int mes;
        int anio;
        string autor;
        Comentario coment;
    public:
        Noticia();
};

class Comentario
{
    private:
        int numero;
        string texto;
        Usuario user;
    public:
        Comentario();
};

class Persona
{
    protected:
        string nombre;
        int dni;
    public:
        Persona();
};

class Autor : public Persona
{
    private:
        string Medio;
    public:
        Autor();
};
class Usuario : public Persona
{
    private:
        int edad;
    public:
        Usuario();
};