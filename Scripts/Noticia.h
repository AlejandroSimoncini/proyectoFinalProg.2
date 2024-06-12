#include <iostream>
#include "Comentario.h"
using namespace std;
const int MAX_COMENTARIOS = 100 ;

// Clase Noticia
class Noticia {
    private:
        string titulo;
        string detalle;
        int dia;
        int mes;
        int anio;
        string dniAutor;
        Comentario comentarios[MAX_COMENTARIOS];
        int numComentarios;
        int proximoNumeroComentario;

    public:
        Noticia();
        Noticia(string tit,string det,int d,int m,int a,string dniA);
        void agregarComentario(Comentario comment);
        void mostrar();
        string toString();
        static Noticia fromString(string& str);
        int getAnio();
        int getMes();
        string getDniAutor();
        string getTitulo();
        Comentario* getComentarios();
        int getNumComentarios();
};