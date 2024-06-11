#include<iostream>
#include<fstream>
#include"Comentario.h"


Comentario::Comentario()
{
    texto = " ";
    numero = 0;
    user = " ";
}

Comentario::Comentario(string com, int num, string usr)
{
    texto = com;
    numero = num;
    user = usr;
}