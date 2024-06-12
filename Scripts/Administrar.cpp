#include <iostream>
#include <fstream>
#include <ctime> 
#include <string>
#include "Administrar.h"

void Administrar::guardarAutor()
{
    ofstream archivo("autores.txt");
    for (int i = 0; i < numAutores; i++)
    {
        archivo << autores[i].toString() << endl;
    }
}

void Administrar::cargarAutor()
{
    ifstream archivo("autores.txt");
    string linea;
    numAutores = 0;
    while (getline(archivo,linea) && numAutores < MAX_AUTORES)
    {
        autores[numAutores++] = Autor::fromString(linea);
    }
}


void Administrar::guardarUsuario()
{
    ofstream archivo("usuarios.txt");
    for (int i = 0 ; i < numAutores ; i++)
    {
        archivo << usuarios[i].toString() << endl; 
    }
}

void Administrar::cargarUsuario()
{
    ifstream archivo("usuarios.txt");
    string linea;
    numUsuarios = 0;
    while (getline(archivo,linea) && numUsuarios<MAX_USUARIOS)
    {
        usuarios[numUsuarios++] = Usuario::fromString(linea);
    }
}

void Administrar::guardarNoticia()
{
    ofstream archivo("noticias.txt");
    for (int i = 0; i < numNoticias; i++)
    {
        archivo << noticias[i].toString() << endl;
        for (int j = 0; j < noticias[i].getNumComentarios(); j++)
        {
            archivo << noticias[i].getComentarios()[j].toString() <<endl;
        }
        archivo << "###" <<endl;
    }
}

void Administrar::cargarNoticia()
{
    ifstream archivo("noticias.txt");
    string linea;
    numNoticias = 0;
    while (getline(archivo,linea) && numNoticias<MAX_NOTICIAS)
    {
        if (linea == "###")
        {
            continue;
        }
        Noticia noticia = Noticia::fromString(linea);
        while (getline(archivo,linea) && linea != "###")
        {
            noticia.agregarComentario(Comentario::fromString(linea));
        }   
        noticias[numNoticias++] = noticia;
    }
}

Administrar::Administrar()
{
    cargarAutor();
    cargarUsuario();
    cargarNoticia();
    numAutores = 0;
    numUsuarios = 0;
    numNoticias = 0;
}

void Administrar::registrarAutor(string dni, string nombre, string medio)
{
    if (numAutores<MAX_AUTORES)
    {
        autores[numAutores++] = Autor(dni,nombre,medio);
        guardarAutor();
    }
    else
    {
        cout << "no se pueden registrar mas autores" <<endl;
    }
}

void Administrar::registrarUsuario(string dni, string nombre, int edad)
{
    if (numUsuarios<MAX_USUARIOS)
    {
        usuarios[numUsuarios++] = Usuario(dni,nombre,edad);
        guardarUsuario();
    }
    else
    {
        cout << "no se pueden registrar mas usuarios" <<endl;
    }
}

void Administrar::registrarNoticia(string titulo, string detalle, int dia, int mes, int año, string dniAutor)
{
    for (int i = 0; i < numAutores; i++)
    {
        if (autores[i].getDni() == dniAutor)
        {
            if (numNoticias < MAX_NOTICIAS)
            {
                noticias[numNoticias++] = Noticia(titulo,detalle,dia,mes,año,dniAutor);
                guardarNoticia();
            }
            else
            {
                cout << "No se pueden registrar mas noticias"<<endl;
            }
        }
        else
        {
            cout <<"ingrese un dni de autor ya registrado"<<endl;
        }
    }
}

void Administrar::registrarComentario(int numero, string texto, string dniUsuario)
{
    cout<<"lista de noticias:"<<endl;
    for (int i = 0; i < numNoticias; i++)
    {
        cout << i+1 << ". " <<noticias[i].getTitulo() << endl;
    }
    int opcion;
    cout << "Seleccione la noticia a comentar (0 para cancelar): ";
    cin >> opcion;

    if (opcion > 0 && opcion <= numNoticias) 
    {        
        for (int i = 0; i < numUsuarios; i++) 
        {
            if (usuarios[i].getDni() == dniUsuario) 
            {
                noticias[opcion - 1].agregarComentario(Comentario(texto,numero,dniUsuario));
                guardarNoticia();
                cout << "Comentario agregado correctamente a la noticia: " << noticias[opcion - 1].getTitulo() << endl;
            }
        }
        cout << "Usuario no encontrado." << endl;
    } 
    else 
    {
        cout << "Operación cancelada." << endl;
    }
}

void Administrar::filtrarAutor()
{
    cout << "Lista de autores " << endl ;
    for (int i = 0 ; i < numAutores ; i++)
    {
        cout << i + 1 << autores[i].getNombre() << endl ;
    }

    int opcion ;  
    cout << "Seleccione un autor para ver sus noticias ; ( 0 si desea salir )" << endl ;
    cin >> opcion ;

    if(opcion > 0 && opcion < numAutores )
    {
        string dniAutor = autores[opcion - 1].getDni();
        cout << "Noticias publicadas por : " << autores[opcion - 1].getDni() << endl ;
        for(int i = 0 ; i < numNoticias ; i++ )
        {
            if(noticias[i].getDniAutor() == dniAutor)
            {
                cout << i + 1 << "." << noticias[i].getTitulo() << endl ;
            }
        }
    
    cout << "Seleccione una noticia para ver detalles; ( 0 para salir ): "  << endl ;
    cin >> opcion ;

        if(opcion > 0 && opcion <= numNoticias)
        {
            noticias [opcion - 1].mostrar();
        }
    }
}

void Administrar::filtrarnoticiasAnio()
{
    
    int anio;
    int opcion;
    cout << "Ingrese el año del que desea leer noticias " << endl ;
    cin >> anio;
    
    cout << "Noticias publicadas en el año "<< anio << ":" << endl ;

    for (int i = 0 ; i < numNoticias ; i++)
    {
        if (noticias[i].getAnio() == anio )
        {
            cout << i + 1 << "." << noticias[i].getTitulo() << endl ;
        }
    }

    cout << "Seleccione una notica para leer ( 0 para salir )" << endl ;
    cin >> opcion ;

    if(opcion > 0 && opcion <= numNoticias)
    {
        noticias [opcion - 1].mostrar();
    }
}

void Administrar::filtrarnoticiasUltmes() {
    time_t t = time(nullptr);
    tm* timePtr = localtime(&t);
    int mesActual = timePtr->tm_mon + 1;
    int anioActual = timePtr->tm_year + 1900;

    for (int i = 0; i < numNoticias; i++) {
        if (noticias[i].getAnio() == anioActual && noticias[i].getMes() == mesActual) {
            noticias[i].mostrar();
        }
    }
}

void Administrar::mostrarNoticiaComentarios()
{
    cout<<"lista de noticias:"<<endl;
    for (int i = 0; i < numNoticias; i++)
    {
        cout << i+1 << ". " <<noticias[i].getTitulo() << endl;
    }
    int opcion;
    cout<<"seleccione una noticia para ver detalles y comentariios (0 para salir)"<<endl;
    cin>> opcion;

    if(opcion > 0 && opcion <= numNoticias)
    {
        noticias[opcion-1].mostrar();
    }
}

void Administrar::menu()
{
    int opcion;
    do{
        cout << "--- Menu ---"<<endl;
        cout << "1. Registrar Autor"<<endl;
        cout << "2. Registrar Usuario"<<endl;
        cout << "3. Cargar Noticia"<<endl;
        cout << "4. Registrar Comentario"<<endl;
        cout << "5. Listar Noticias por Año"<<endl;
        cout << "6. Listar Noticias del Último Mes"<<endl;
        cout << "7. Mostrar Noticia y Comentarios"<<endl;
        cout << "8. Listar Noticias por Autor"<<endl;
        cout << "0. Salir"<<endl;
        cout << "Seleccione una opción: "<<endl;
        cin >> opcion;

        switch (opcion) {
            case 1:{
                string dni, nombre, medio;
                cout << "Ingrese DNI: "<<endl;
                cin>>dni;
                cout << "Ingrese nombre: "<<endl;
                cin>>nombre;
                cout << "Ingrese medio: "<<endl;
                cin>>medio;
                registrarAutor(dni, nombre, medio);
                break;
            }
            case 2: {
                string dni, nombre;
                int edad;
                cout << "Ingrese DNI: "<<endl;
                cin>>dni;
                cout << "Ingrese nombre: "<<endl;
                cin>>nombre;
                cout << "Ingrese edad: "<<endl;
                cin>>edad;
                registrarUsuario(dni, nombre, edad);
                break;
            }
            case 3: {
                string titulo, detalle, dniAutor;
                int dia, mes, año;
                cout << "Ingrese título: "<<endl;
                cin>>titulo;
                cout << "Ingrese detalle: "<<endl;
                cin>>detalle;
                cout << "Ingrese día: "<<endl;
                cin >> dia;
                cout << "Ingrese mes: "<<endl;
                cin >> mes;
                cout << "Ingrese año: "<<endl;
                cin >> año;
                cout << "Ingrese DNI del autor: "<<endl;
                cin>>dniAutor;
                registrarNoticia(titulo, detalle, dia, mes, año, dniAutor);
                break;
            }
            case 4: {
                int numero;
                string texto, dniUsuario, tituloNoticia;
                cout << "Ingrese número de comentario: "<<endl;
                cin >> numero;
                cout << "Ingrese texto del comentario: "<<endl;
                cin>>texto;
                cout << "Ingrese DNI del usuario: "<<endl;
                cin>>dniUsuario;
                registrarComentario(numero, texto, dniUsuario);
                break;
            }
            case 5:{
                filtrarnoticiasAnio();
                break;
            }
            case 6:{
                filtrarnoticiasUltmes();
                break;
            }
            case 7:{
                mostrarNoticiaComentarios();
                break;
            }
            case 8:{
                filtrarAutor();
                break;
            }
            case 0:{
                cout << "Saliendo..."<<endl;
                break;
            }
            default:{
                cout << "Opción no válida."<<endl;
            }
        } 
    }while (opcion != 0);
}