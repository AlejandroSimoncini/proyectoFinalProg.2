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
    public:
        Noticia();
        Noticia(string tit,string det,int d,int m,int a);
};