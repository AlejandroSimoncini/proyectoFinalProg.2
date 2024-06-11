#include <iostream>
#include "Comentario.h"
using namespace std;

class Noticia
{
    private:
        string titulo;
        string detalle;
        int dia;
        int mes;
        int anio;
        Comentario com[5];
    public:
        Noticia();
        Noticia(string tit,string det,int d,int m,int a);
        void guardarNoticia();
        void AgregarComentario(Comentario c);
};