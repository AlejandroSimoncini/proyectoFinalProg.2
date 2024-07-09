#include<iostream>
#include <sstream>
#include <string>
#include"Comentario.h"

Comentario::Comentario()
{
    texto = "";
    numero = 0;
    dniUsuario = "";
    nombreUsuario = "";
}

Comentario::Comentario(string com, int num, string dniusr,string nomUsr)
{
    texto = com;
    numero = num;
    dniUsuario = dniusr;
    nombreUsuario=nomUsr;
}

string Comentario::toString() const
{
    return to_string(numero) + "," + texto + "," + dniUsuario + "," + nombreUsuario;
}

Comentario Comentario::fromString(const string& datos)
{
    stringstream ss(datos);
    string texto,strNumero,dniUser,nomUser;
    getline(ss,strNumero,',');
    getline(ss,texto,',');
    getline(ss,dniUser,',');
    getline(ss,nomUser,',');
    int num = stoi(strNumero);
    return Comentario(texto,num,dniUser,nomUser);
}

string Comentario::getDniUsuario()
{
    return dniUsuario;
}

void Comentario::setNumero(int num)
{
    numero = num;
}

void Comentario::mostrar()
{
    cout << "Comentario #" << numero << " por " << nombreUsuario << ": " << texto << endl;
}