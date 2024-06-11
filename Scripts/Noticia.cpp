#include <iostream>
#include <fstream>
#include "Noticia.h"

Noticia::Noticia()
{
    titulo = " ";
    detalle = " ";

    dia = 0;
    mes = 0;
    anio = 0;
    Comentario();
}

Noticia::Noticia(string tit, string det, int d, int m, int a)
{
    titulo = tit;
    detalle = det;

    dia = d;
    mes = m;
    anio = a;
    Comentario();
}

void Noticia::AgregarComentario(Comentario c)
{
    for (int i = 0; i < 5; i++)
    {
        if (com[i].numero == 0 and com[i].user == " " and com[i].texto == " ")
        {
            cin >> com->user;
            com->numero = i+1;
            cout << com->numero;
            cin >> com->texto;
        }
    }
}

void Noticia::guardarNoticia()
{
    ofstream escribirN("noticias.txt"); //se incluye el ios::app para que los datos agregados se pongan uno encima de otro
    if (escribirN.is_open())
    {
        escribirN << dia << "/" << mes << "/" << anio;
        escribirN << endl;
        escribirN << titulo;
        escribirN << endl;
        escribirN << detalle;
        escribirN << endl;
        for (int i = 0; i < 5; i++)
        {
            if (com[i].texto != " ")
            {
            escribirN << com[i].numero << endl;
            escribirN << com[i].user << endl;
            escribirN << com[i].texto << endl;
            escribirN << endl;
            escribirN << endl;
            }
        }
    }
}