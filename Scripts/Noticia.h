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
        string nombreAutor;
        Comentario comentarios[MAX_COMENTARIOS];
        int numComentarios;
        int proximoNumeroComentario;

    public:
        Noticia();
        Noticia(string tit,string det,int d,int m,int a,string dniA,string nombreA);
        void agregarComentario(Comentario comment);
        void mostrar();
        string toString();
        static Noticia fromString(const string& datos);
        int getAnio();
        int getMes();
        string getDniAutor();
        string getTitulo();
        const Comentario* getComentarios() const;
        int getNumComentarios();
        string getNombreAutor();
};