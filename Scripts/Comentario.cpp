#include<iostream>
#include <sstream>
#include <string>
#include"Comentario.h"

Comentario::Comentario()
{
    texto = "";
    numero = 0;
    dniUsuario = "";
}

Comentario::Comentario(string com, int num, string usr)
{
    texto = com;
    numero = num;
    dniUsuario = usr;
}

string Comentario::toString()const
{
    return to_string(numero) + "," + texto + "," + dniUsuario;
}

Comentario Comentario::fromString(const string& datos)
{
    stringstream ss(datos);
    string texto,strNumero,dniUser;
    getline(ss,strNumero,',');
    getline(ss,texto,',');
    getline(ss,dniUser,',');
    int num = stoi(strNumero);
    return Comentario(texto,num,dniUser);
}

string Comentario::getDniUsuario()const
{
    return dniUsuario;
}

void Comentario::setNumero(int num)
{
    numero = num;
}

void Comentario::mostrar()const
{
    cout << "Comentario #" << numero << " por " << dniUsuario << ": " << texto << endl;
}