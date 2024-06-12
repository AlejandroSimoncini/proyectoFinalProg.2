#include <iostream>
#include <string>
#include <sstream>
#include "Noticia.h"

Noticia::Noticia()
{
    titulo = "";
    detalle = "";
    dia = 0;
    mes = 0;
    anio = 0;
    dniAutor = "";
    numComentarios = 0 ;
    proximoNumeroComentario = 1 ;
}

Noticia::Noticia(string tit, string det, int d, int m, int a,string dniA)
{
    titulo = tit;
    detalle = det;
    dia = d;
    mes = m;
    anio = a;
    dniAutor = dniA;
    numComentarios = 0 ;
    proximoNumeroComentario = 1 ;
}

void Noticia::agregarComentario(Comentario comment)
{
    if (numComentarios<MAX_COMENTARIOS)
    {
        comentarios->setNumero(proximoNumeroComentario++);
        comentarios[numComentarios++]=comment;
    }
}

void Noticia::mostrar()const
{
    cout << "Titulo: " << titulo << endl;
    cout << "Detalle: " << detalle << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Autor: " << dniAutor << endl;
    cout << "Comentarios: " << endl;
    for (int i = 0; i < numComentarios; i++) {
        comentarios[i].mostrar();
    }
}

string Noticia::toString()  const
{
    return titulo + "," + detalle + "," + to_string(dia) + "," + to_string(mes) + "," + to_string(anio) + "," + dniAutor;
}

Noticia Noticia::fromString(const string& datos) 
{
    stringstream ss(datos);
    string titulo, detalle, diaStr, mesStr, anioStr, dniAutor;
    getline(ss, titulo, ',');
    getline(ss, detalle, ',');
    getline(ss, diaStr, ',');
    getline(ss, mesStr, ',');
    getline(ss, anioStr, ',');
    getline(ss, dniAutor, ',');
    int dia = stoi(diaStr);
    int mes = stoi(mesStr);
    int anio = stoi(anioStr);
    return Noticia(titulo, detalle, dia, mes, anio, dniAutor);
}

int Noticia::getAnio() const
{
    return anio;
}

int Noticia::getMes()const
{
    return mes; 
}

string Noticia::getDniAutor() const
{
    return dniAutor;
}

string Noticia::getTitulo()  const
{
    return titulo; 
}

const Comentario* Noticia::getComentarios() const
{
    return comentarios;
}
    
int Noticia::getNumComentarios() const
{
    return numComentarios;
}