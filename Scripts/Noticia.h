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
        void mostrar()const;
        string toString()const;
        static Noticia fromString(const string& datos);
        int getAnio()const;
        int getMes()const;
        string getDniAutor()const;
        string getTitulo()const;
        const Comentario* getComentarios() const;
        int getNumComentarios()const;
};