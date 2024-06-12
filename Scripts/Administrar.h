#include <iostream>
#include "Noticia.h"
#include "Autor.h"
#include "Usuario.h"
using namespace std;

const int MAX_AUTORES = 100;
const int MAX_USUARIOS = 100;
const int MAX_NOTICIAS = 100;
class Administrar
{
    private:
        Noticia noticias[MAX_NOTICIAS];
        Usuario usuarios[MAX_USUARIOS];
        Autor autores[MAX_AUTORES];
        int numAutores;
        int numUsuarios;
        int numNoticias;
        void guardarAutores()const;
        void cargarAutores();
        void guardarUsuarios()const;
        void cargarUsuarios ();
        void guardarNoticias()const;
        void cargarNoticias();
    public:
        Administrar();

        void registrarAutor(string dni, string nombre, string medio);

        void registrarUsuario(string dni, string nombre, int edad);

        
        void cargarNoticia(string titulo, string detalle, int dia, int mes, int año, string dniAutor);

        void registrarComentario(int numero, string texto, string dniUsuario);
        
        void listarNoticiasAnio()const;
        void listarNoticiasUltimoMes()const;
        void listarNoticiasAutor();
        void mostrarNoticiaYComentarios()const;
        
        void menu();
};