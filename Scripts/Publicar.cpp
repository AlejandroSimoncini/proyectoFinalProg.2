#include <iostream>
#include "Publicar.h"
#include "Autor.h"
#include "Usuario.h"

void Publicar::RegistrarAutor()
{
    int dni;
    string nom, med;
    cout<<"Ingrese DNI"<<endl;
    cin>>dni;
    cout<<"Ingrese nombre del autor"<<endl;
    cin>>nom;
    cout<<"Ingrese medio del autor"<<endl;
    cin>>med;

    Autor autor(dni,nom,med);
    autor.GuardarAutor();
}

void Publicar::RegistrarUsuario()
{
    int eda,dni;
    string nom;
    cout<<"Ingrese DNI"<<endl;
    cin>>dni;
    cout<<"Ingrese nombre del usuario"<<endl;
    cin>>nom;
    cout<<"Ingrese la edad del usuario"<<endl;
    cin>>eda;

    Usuario usuario(dni,nom,eda);
    usuario.GuardarUsuario();
}