#include <iostream>
#include "Comentario.h"
#include "Noticia.h"
#include "Autor.h"
using namespace std;

class Administrar
{
    private:
        Autor **autores;
        int cantidadAutores;
        Usuario **usuarios;
        int cantidadUsuarios;
    public:
        ~Administrar()
        void subirNoticia();
        void subirComentario();
        void registrarUsuario();
        void registrarAutor();
        void iniciarSesionUsuario();
        void iniciarSesionAutor();
        void mostrarNoticia();
        void noticiasPorAnio();
        void noticiasPorMes();
        void noticiasPorAutor();
};