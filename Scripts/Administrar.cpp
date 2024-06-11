#include <iostream>
#include "Administrar.h"
#include "Autor.h"
#include "Usuario.h"

Administrar::~Administrar() 
{
    int cantidad;
    if (cantidadAutores>cantidadUsuarios)
    {
        cantidad = cantidadAutores;
    }
    else
    {
        cantidad = cantidadUsuarios;
    }
    
    for (int i = 0; i < cantidad; ++i) 
    {
        delete autores[i];  
    }
    delete[] autores;  
}

void Administrar::registrarAutor()
{
    int dni;
    string nom, med;
    cout<<"Ingrese DNI"<<endl;
    cin>>dni;
    cout<<"Ingrese nombre del autor"<<endl;
    cin>>nom;
    cout<<"Ingrese medio del autor"<<endl;
    cin>>med;

    autores = new Autor*[100];
    autores[cantidadAutores] = new Autor(dni,nom,med);
    autores[cantidadAutores] -> guardarAutor();
    cantidadAutores++;
}

void Administrar::registrarUsuario()
{
    int eda,dni;
    string nom;
    cout<<"Ingrese DNI"<<endl;
    cin>>dni;
    cout<<"Ingrese nombre del usuario"<<endl;
    cin>>nom;
    cout<<"Ingrese la edad del usuario"<<endl;
    cin>>eda;

    usuarios = new Usuario*[100];
    usuarios[cantidadUsuarios] = new Autor(dni,nom,med);
    usuarios[cantidadUsuarios] -> guardarAutor();
    cantidadUsuarios++;
}

void Administrar::subirNoticia()
{
    string tit,det;
    int d,m,a;
    
    cout<<"Ingrese el titulo de la noticia"<<endl;
    cin>>tit;
    cout<<"Ingrese el contenido de la noticia"<<endl;
    cin>>det;
    cout<<"Ingrese el dia de publicacion"<<endl;
    cin>>d;
    cout<<"Ingrese el mes de publicacion"<<endl;
    cin>>m;
    cout<<"Ingrese el año de publicacion"<<endl;
    cin>>a;

    Noticia noticia(tit,det,d,m,a);
    noticia.guardarNoticia();
}

void Administrar::subirComentario()
{
    string text,usr;
    int num;

    cout<<"Ingresa el comentario"<<endl;
    cin>>text;
    usr = getUsuario();
}

void Administrar::iniciarSesionUsuario()
{
    
}