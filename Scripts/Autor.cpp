#include"Autor.h"
#include <fstream>

Autor::Autor(int dni , string nom , string medi) : Persona(dni, nom)
{
    medio = medi ;
}

string Autor::getmedio()
{
    return medio ;
}

void Autor::guardarAutor()
{
    ofstream escribirA ("autores.txt");

    if (escribirA.is_open())
    {
        escribirA << Nombre << endl ;
        escribirA << medio << endl ;
        escribirA << DNI << endl ;
        escribirA.close();
    }

    
}
