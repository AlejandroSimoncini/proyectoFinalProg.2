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
    nombreAutor= "";
    numComentarios = 0 ;
    proximoNumeroComentario = 1 ;
}

Noticia::Noticia(string tit, string det, int d, int m, int a,string dniA,string nombreA)
{
    titulo = tit;
    detalle = det;
    dia = d;
    mes = m;
    anio = a;
    dniAutor = dniA;
    nombreAutor = nombreA;
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

void Noticia::mostrar()
{
    cout << "Titulo: " << titulo << endl;
    cout << "Detalle: " << detalle << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << "Autor: " << nombreAutor << endl;
    cout << "Comentarios: " << endl;
    for (int i = 0; i < numComentarios; i++) {
        comentarios[i].mostrar();
    }
}

string Noticia::toString()  
{
    return titulo + "," + detalle + "," + to_string(dia) + "," + to_string(mes) + "," + to_string(anio) + "," + dniAutor + "," + nombreAutor;
}

Noticia Noticia::fromString(const string& datos) 
{
    stringstream ss(datos);
    string titulo, detalle, diaStr, mesStr, anioStr, dniAutor,nombreAutor;
    getline(ss, titulo, ',');
    getline(ss, detalle, ',');
    getline(ss, diaStr, ',');
    getline(ss, mesStr, ',');
    getline(ss, anioStr, ',');
    getline(ss, dniAutor, ',');
    getline(ss, nombreAutor, ',');
    int dia = stoi(diaStr);
    int mes = stoi(mesStr);
    int anio = stoi(anioStr);
    return Noticia(titulo, detalle, dia, mes, anio, dniAutor,nombreAutor);
}

int Noticia::getAnio() 
{
    return anio;
}

int Noticia::getMes()
{
    return mes; 
}

string Noticia::getDniAutor() 
{
    return dniAutor;
}

string Noticia::getTitulo()  
{
    return titulo; 
}

const Comentario* Noticia::getComentarios() const
{
    return comentarios;
}
    
int Noticia::getNumComentarios() 
{
    return numComentarios;
}

string Noticia::getNombreAutor()
{
    return nombreAutor;
}