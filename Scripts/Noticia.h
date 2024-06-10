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
        Comentario *com;
    public:
        Noticia();
        Noticia(string tit,string det,int d,int m,int a);
        Noticia(string tit,string det,int d,int m,int a,Comentario c);
        void AgregarComentario(Comentario c);
};